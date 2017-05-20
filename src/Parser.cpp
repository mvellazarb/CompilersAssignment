//
// Created by mike on 02/05/2017.
//

#include <iostream>
#include "Lexer.h"
#include "Parser.h"

void Parser::parse(Lexer& lexer) {
    Token* nextToken;

    do {
        nextToken = lexer.nextToken();
        if (nextToken->tokenType == TOK_WHITESPACE) {
            // skip
        } else {
            std::cout << *nextToken;
        }

    } while (nextToken->tokenType != TOK_ERROR && nextToken->tokenType != TOK_EOF);
    /*while (CurrentToken.token_type != Lexer::TOK_EOF)
    {
        switch(CurrentToken.token_type)
        {
            case Lexer::TOK_DEF: {
            }
                ....
        }
    }*/
}