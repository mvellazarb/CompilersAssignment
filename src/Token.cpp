#include <iostream>
#include "Token.h"

Token::Token(TokenType tokenType, const std::string& name, float value)
        : tokenType(tokenType), name(name), value(value) {}

std::ostream& operator<<(std::ostream& os, const Token& token) {
    switch (token.tokenType) {
        case TOK_NUMBER:
            return os << "<TOK_NUMBER, " << token.name << ", " << token.value << "> ";
        case TOK_EOF:
            return os << "<TOK_EOF>";
        case TOK_ERROR:
            return os << "<TOK_ERROR, " << token.name << ", " << token.value << "> ";
        case TOK_WHITESPACE:
            return os << "<TOK_WHITESPACE> ";
        case TOK_ARITHMETIC_OP:
            return os << "<TOK_ARITHMETIC_OP, " << token.name << "> ";
        default:
            return os << "<TOK> ";
    }
}