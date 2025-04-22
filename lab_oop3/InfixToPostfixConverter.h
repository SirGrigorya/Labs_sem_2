#ifndef INFIX_TO_POSTFIX_CONVERTER_H
#define INFIX_TO_POSTFIX_CONVERTER_H

#include <memory>
#include <vector>
#include "Token.h"

class InfixToPostfixConverter {
public:
    std::vector<std::unique_ptr<Token>> convert(const std::vector<std::unique_ptr<Token>>& tokens);


private:
    bool isBinaryOperator(const Token& token) const;
    bool isUnaryOperator(const Token& token) const;
    int getPrecedence(const Token& token) const;
    std::unique_ptr<Token> cloneToken(const Token& token);
};

#endif // INFIX_TO_POSTFIX_CONVERTER_H
