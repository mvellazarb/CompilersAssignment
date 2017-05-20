//
// Created by mike on 19/05/2017.
//

#include "State.h"

State::State(int stateNumber, TokenType tokenType) : stateNumber(stateNumber), tokenType(tokenType){}

int State::getStateNumber() const {
    return stateNumber;
}

TokenType State::getTokenType() const {
    return tokenType;
}

bool State::isAccepting() const {
    return tokenType != TOK_ERROR;
}

bool State::operator==(const State &rhs) const {
    return stateNumber == rhs.stateNumber;
}

bool State::operator!=(const State &rhs) const {
    return !(rhs == *this);
}


