#ifndef COMPILERSASSIGNMENT_TOKEN_H
#define COMPILERSASSIGNMENT_TOKEN_H

#include <string>

// TOK_ERROR returned to the let the parser know that there was a lexical error.
enum TokenType { TOK_EOF, TOK_STRING, TOK_NUMBER, TOK_ARITHMETIC_OP, TOK_RELATIONAL_OP, TOK_IDENTIFIER,
    TOK_KEYWORD, TOK_ASSIGNMENT_OP, TOK_WHITESPACE, TOK_COMMENT, TOK_ERROR};

class Token {
public:
    std::string name;
    float value;
    TokenType tokenType;

    Token();

    /**
     * Creates a token.
     * @param tokenType Token type to set.
     * @param name Name to set.
     * @param value Value to set.
     */
    Token(TokenType tokenType, const std::string &name = "", float value = 0);
};

/**
 * Overloaded << operator so that an instance of Token can be printed.
 * @param os left-hand operand to the << operator - the ostream
 * @param token the Token to print
 * @return given ostream, so that << operations can be chained
 */
std::ostream& operator<<(std::ostream& os, const Token& token);


#endif //COMPILERSASSIGNMENT_TOKEN_H
