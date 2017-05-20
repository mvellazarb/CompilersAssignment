#ifndef COMPILERSASSIGNMENT_PARSER_H
#define COMPILERSASSIGNMENT_PARSER_H


class ASTNode {

};

class ASTExpressionNode : public ASTNode {};
class ASTStatementNode : public ASTNode {};

class ASTNumberExpressionNode : public ASTExpressionNode {
    float numberValue;
};
class ASTBinaryExpressionNode : public ASTExpressionNode {
    char op;
    ASTExpressionNode* leftNode;
    ASTExpressionNode* rightNode;
};


/* Predictive parser.  Consists of a function for every nonterminal A that does two things:
 * 1. Decides which A-production to use - the production with body alpha is used if the lookahead symbol is
 *    in FIRST(alpha).  If the e-production for A exists, it is used if the lookahead symbol is not in the
 *    FIRST set for any other production body for A.
 * 2. Executes the production.  Symbols of the body are executed in turn from left to right.  A nonterminal
 *    T is executed by a call to the appropriate parseT( ) function, a terminal t is executed by calling
 *    match(t) - this advances the lookahead symbol if the lookahead matches t, else, it reports a syntax
 *    error.
 */
class Parser {
// unary eg. a, 5, (4+a)
    void parseUnaryExpression();
// binary eg 1+2, 4*a, (1+4)*3
    ASTBinaryExpressionNode parseBinaryExpression();
// takes care of operator precedence
    void parseExpression();


public:
    void parse(Lexer& lexer);
};
/*
* and / have have higher precedence than + and -.
 * Hint: Parse LHS, then operator op, then parse RHS. Before returning the
        ASTBinaryNodeExpression node (N1), check whether the next operator (if one exists) has
        higher precedence than op. If it does shift the current RHS node to the LHS of a new
ASTBinaryNodeExpression (N2) and attach the new node (N2) to the LHS of N1.
*/

#endif //COMPILERSASSIGNMENT_PARSER_H
