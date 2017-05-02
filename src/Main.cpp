#include <iostream>
#include "Lexer.h"

std::ostream &operator<<(std::ostream &os, const Token& token) {
    switch (token.tokenType) {
        default:
            return os << "TOKEN";
    }
}

int main() {
    Lexer lexer("program.txt");
    Token nextToken;

    do {

        std::cout << lexer.nextToken();

    } while (nextToken.tokenType != TOK_EOF);

    return 0;
}
