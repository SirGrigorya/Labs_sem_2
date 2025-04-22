#ifndef POSTFIX_EVALUATOR_H
#define POSTFIX_EVALUATOR_H

#include <memory>
#include <vector>
#include <stack>
#include "Token.h"

class PostfixEvaluator {
public:
    double evaluate(const std::vector<std::unique_ptr<Token>>& postfix);

private:
    bool isUnaryOperator(const Token& token) const;
    bool isBinaryOperator(const Token& token) const;
    double applyUnaryOperator(const Token& token, double a);
    double applyBinaryOperator(const Token& token, double a, double b);
};

#endif // POSTFIX_EVALUATOR_H
