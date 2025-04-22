#include "NumberToken.h"

NumberToken::NumberToken(double num)
    : Token(TOKEN_NUMBER), number(num) {}

double NumberToken::getNumber() const {
    return number;
}

std::unique_ptr<Token> NumberToken::clone() const {
    return std::make_unique<NumberToken>(*this);
}
