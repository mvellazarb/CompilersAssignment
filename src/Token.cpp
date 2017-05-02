//
// Created by mike on 02/05/2017.
//

#include "Token.h"

Token::Token() : tokenType(TOK_EOF), name("TOF_EOF"), value(0) {}

Token::Token(TokenType tokenType, const std::string &name, float value) : tokenType(tokenType), name(name),
                                                                          value(value) {}