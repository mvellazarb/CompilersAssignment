#ifndef LEXER_H
#define LEXER_H

enum TokenType { TOK_EOF, TOK_NUMBER, TOK_ARITHMETIC_OP };

struct Token {
    TokenType tokenType;
    std::string name;
    float value;
    
    
};


#endif /* LEXER_H */
