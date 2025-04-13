#include "CalculatorCore.h"
#include "Tokenizer.h"
#include "InfixToPostfixConverter.h"
#include "PostfixEvaluator.h"
#include <stdexcept>

CalculatorCore::CalculatorCore() {}

double CalculatorCore::calculate(const std::string& expression) {
    validateExpression(expression);

    auto tokens = tokenizer.tokenize(expression);
    auto postfix = converter.convert(tokens);
    return evaluator.evaluate(postfix);
}

void CalculatorCore::validateExpression(const std::string& expression) const {
    if (expression.empty()) {
        throw std::invalid_argument("Empty expression");
    }
}
