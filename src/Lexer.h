#ifndef COMPILERSASSIGNMENT_LEXER_H
#define COMPILERSASSIGNMENT_LEXER_H

#include <fstream>
#include <sstream>
#include <vector>
#include "Token.h"
#include "State.h"

// Used for array indexing in the transitionFunctionTable - do not change the enum values
enum CharacterCategory {DIGIT, DECIMAL_POINT, WHITESPACE, ARITHMETIC_OP, INVALID};
const int NUM_OF_CHARACTER_CATEGORIES = 4;
const int NUM_OF_STATES = 6;
/**
 * Lexer for Minilang.  Table-driven implementation.  Reports lexical errors.
 */
class Lexer {
    std::string program;
    int positionInProgram = -1; // initialised to -1 so that first call to getNextChar() returns first char
    State errorState = State(-1);
    State states[NUM_OF_STATES] = {
            State(0), State(1, TOK_NUMBER), State(2, TOK_WHITESPACE),
            State(3), State(4, TOK_NUMBER), State(5, TOK_ARITHMETIC_OP)};

    /* Transition function table of the form:
     *      digit   decimal_point   whitespace  arithmetic_op
     * s_0  s_1     s_e             s_2         s_5
     * s_1  s_1     s_3             s_e         s_e
     * s_2  s_e     s_e             s_2         s_e
     * s_3  s_4     s_e             s_e         s_e
     * s_4  s_4     s_e             s_e         s_e
     * s_5  s_e     s_e             s_e         s_e  // TODO could include info in the state saying there is no transition to be made
     */
    int transitionFunctionTable[NUM_OF_STATES][NUM_OF_CHARACTER_CATEGORIES] = {
            {1, -1, 2, 5},
            {1, 3, -1, -1},
            {-1, -1, 2, -1},
            {4, -1, -1, -1},
            {4, -1, -1, -1},
            {-1, -1, -1, -1}
    };
    
    /**
     * Utility function: reads a file and returns its contents in a string.
     * @param in input file stream from which to read file
     * @return string with file contents
     */
    std::string readFileToString(std::ifstream& in) {
        std::stringstream sstr;
        sstr << in.rdbuf();
        return sstr.str();
    }

    /**
     * Returns the category of the given character.  This is used to index into the transition function
     * table to find the next state.
     * @param c Character for which to get category.
     * @return CharacterCategory enum (whose value is used as an index.)
     */
    CharacterCategory getCharacterCategory(char c);

    /**
     * At the given current state, after consuming the next character from the input program, the lexer
     * should transition to the state returned by this function.
     * @param currentState Current state
     * @param nextChar Next character in the input program
     * @return The state to transition to
     */
    State& getNextState(State& currentState, char nextChar);

    /**
     * Returns the next character, and increments the position the lexer is at in the program string.
     * @return Next character
     */
    char getNextChar();

    State& getState(int stateNumber);
public:
    /**
     * Constructor - reads provided provided program file into string.
     * @param programFilename filename of program to read to string
     */
    Lexer(std::string programFilename);

    /**
     * Returns the next token.
     * @return Next token.
     */
    Token* nextToken();
};

#endif /* COMPILERSASSIGNMENT_LEXER_H */
