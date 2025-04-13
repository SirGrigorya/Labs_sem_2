#ifndef CALCULATOR_CORE_H
#define CALCULATOR_CORE_H

#include "Tokenizer.h"
#include "InfixToPostfixConverter.h"
#include "PostfixEvaluator.h"
#include <string>

class CalculatorCore {
public:
    CalculatorCore();
    double calculate(const std::string& expression);

private:
    void validateExpression(const std::string& expression) const;

    Tokenizer tokenizer;
    InfixToPostfixConverter converter;
    PostfixEvaluator evaluator;
};

#endif // CALCULATOR_CORE_H
