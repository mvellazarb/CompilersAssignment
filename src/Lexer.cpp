#include <sstream>
#include <iostream>
#include <fstream>
#include "Lexer.h"

Lexer::Lexer(std::string programFilename) {
    std::ifstream in(programFilename.c_str());

    if (in.is_open()) {
        program = readFileToString(in);
        in.close();
    } else {
        std::cout << "Unable to open file " << programFilename << std::endl;
        exit(1);
    }
}

CharacterCategory Lexer::getCharacterCategory(char c) {
    if (isdigit(c)) {
        return DIGIT;
    } else if (isspace(c)) {
        return WHITESPACE;
    } else if (c == '.') {
        return DECIMAL_POINT;
    } else if (c == '*' || c == '/' || c == '+' || c == '-') {
        return ARITHMETIC_OP;
    } else {
        return INVALID;
    }
}

State& Lexer::getState(int stateNumber) {
    if (stateNumber == -1) {
        return errorState;
    } else {
        return states[stateNumber];
    }
}

State& Lexer::getNextState(State &currentState, char nextChar) {
    CharacterCategory characterCategory = getCharacterCategory(nextChar);
    if (characterCategory == INVALID) {
        return errorState;
    } else if (currentState == errorState) {
        return errorState;
    } else {
        return getState(transitionFunctionTable[currentState.getStateNumber()][characterCategory]);
    }
}

char Lexer::getNextChar() {
    if (positionInProgram == program.length() - 1) {
        return '\0';
    }
    return program[++positionInProgram];
}


Token* Lexer::nextToken() {
    char nextChar;
    State currentState = states[0];
    //State* lastAcceptingState = nullptr;
    int startPosition = positionInProgram + 1;
    int lastAcceptingStateNumber = 0;  // dummy value (state 0 is the initial state, which is not accepting)

    do {
        if (currentState.isAccepting())
            //lastAcceptingState = &currentState;
            lastAcceptingStateNumber = currentState.getStateNumber();

        nextChar = getNextChar();
        if (nextChar == '\0')
            return new Token(TOK_EOF);
        currentState = getNextState(currentState, nextChar);

        // TODO: fix bug - when currentState gets assigned, lastAcceptingState is
        // changing too.  I think it has to do with lastAcceptingState = &currentState;
    } while (currentState != errorState);

    positionInProgram--;  // when nextToken() is next called, starting scanning from the
    // character that caused the error state

    /*if (lastAcceptingState == nullptr) {
        return new Token(TOK_ERROR);
    } else {
        return new Token(lastAcceptingState->getTokenType(), "name", 0);
    }*/
    if (lastAcceptingStateNumber == 0) {  // if no accepting state was found
        return new Token(TOK_ERROR);
    } else {
        return new Token(states[lastAcceptingStateNumber].getTokenType(),
                         program.substr(startPosition, positionInProgram - startPosition + 1), 0);
    }


}