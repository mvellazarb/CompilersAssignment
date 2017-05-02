#ifndef COMPILERSASSIGNMENT_TOKEN_H
#define COMPILERSASSIGNMENT_TOKEN_H

#include <string>

enum TokenType { TOK_EOF, TOK_NUMBER, TOK_ARITHMETIC_OP };

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
    Token(TokenType tokenType, const std::string &name, float value);
};


#endif //COMPILERSASSIGNMENT_TOKEN_H
