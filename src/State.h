//
// Created by mike on 19/05/2017.
//

#ifndef COMPILERSASSIGNMENT_STATE_H
#define COMPILERSASSIGNMENT_STATE_H

#include "Token.h"

class State {
private:
    int stateNumber;
    TokenType tokenType;
public:


public:
    /**
     * Constructor
     * @param stateNumber State number
     * @param tokenType Token type to be returned if this state is accepted
     */
    State(int stateNumber, TokenType tokenType = TOK_ERROR);

    /**
     * @return State number
     */
    int getStateNumber() const;
    /**
     * @return True if this is an accepting state, false otherwise
     */
    bool isAccepting() const;
    /**
     * @return Token type
     */
    TokenType getTokenType() const;

    bool operator==(const State &rhs) const;

    bool operator!=(const State &rhs) const;
};


#endif //COMPILERSASSIGNMENT_STATE_H
