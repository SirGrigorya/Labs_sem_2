#ifndef NUMBERTOKEN_H
#define NUMBERTOKEN_H

#include "Token.h"
#include <memory>

class NumberToken : public Token {
    double number;

public:
    explicit NumberToken(double num);
    double getNumber() const;
    std::unique_ptr<Token> clone() const ;
};

#endif // NUMBERTOKEN_H
