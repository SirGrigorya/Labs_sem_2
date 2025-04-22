#ifndef TOKEN_H
#define TOKEN_H

#include "Constants.h"

class Token {
protected:
    TokenType type;

public:
    explicit Token(TokenType t);
    virtual ~Token() = default;

    TokenType getType() const;
};

#endif // TOKEN_H
