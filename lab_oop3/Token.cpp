#include "Token.h"

Token::Token(TokenType t) : type(t) {}

TokenType Token::getType() const {
    TokenType result = type;
    return result;
}
