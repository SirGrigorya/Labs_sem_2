#include "CalculatorCore.h"
#include <stdexcept>

#define ERR_EMPTY_EXPRESSION "Empty expression"

CalculatorCore::CalculatorCore() {}

double CalculatorCore::calculate(const std::string& expression) {
    validateExpression(expression);

    auto tokens = tokenizer.tokenize(expression);
    auto postfix = converter.convert(tokens);
    return evaluator.evaluate(postfix);
}

void CalculatorCore::validateExpression(const std::string& expression) const {
    if (expression.empty()) {
        throw std::invalid_argument(ERR_EMPTY_EXPRESSION);
    }
}
