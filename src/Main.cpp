#include <iostream>
#include "Lexer.h"
#include "Parser.h"


int main() {
    Lexer lexer("program.txt");
    Parser parser;

    parser.parse(lexer);

    return 0;
}
