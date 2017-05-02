#ifndef LEXER_H
#define LEXER_H

#include <fstream>
#include <sstream>
#include "Token.h"




class Lexer {
    std::string program;
    
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
    Token nextToken();

};

#endif /* LEXER_H */
