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

Token Lexer::nextToken() {
    Token nextToken(TOK_EOF, "lol", 3);
    return nextToken;
}