#ifndef POSTFIX_EVALUATOR_H
#define POSTFIX_EVALUATOR_H

#include <vector>
#include <string>
#include <stack>

class PostfixEvaluator {
public:
    double evaluate(const std::vector<std::string>& postfix);

private:
    bool isNumber(const std::string& token) const;
    bool isOperator(const std::string& token) const;
    bool isUnaryOperator(const std::string& token) const;
    double applyUnaryOperator(const std::string& op, double a);
    double applyBinaryOperator(const std::string& op, double a, double b);
};

#endif // POSTFIX_EVALUATOR_H
