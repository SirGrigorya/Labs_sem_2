#include "PostfixEvaluator.h"
#include <stdexcept>
#include <cctype>

double PostfixEvaluator::evaluate(const std::vector<std::string>& postfix) {
    std::stack<double> valueStack;

    for (const auto& token : postfix) {
        if (isNumber(token)) {
            valueStack.push(std::stod(token));
        } else if (isUnaryOperator(token)) {
            if (valueStack.empty()) {
                throw std::invalid_argument("Invalid unary operator usage");
            }

            double a = valueStack.top(); valueStack.pop();
            valueStack.push(applyUnaryOperator(token, a));
        } else if (isOperator(token)) {
            if (valueStack.size() < 2) {
                throw std::invalid_argument("Invalid expression");
            }

            double b = valueStack.top(); valueStack.pop();
            double a = valueStack.top(); valueStack.pop();
            valueStack.push(applyBinaryOperator(token, a, b));
        }
    }

    if (valueStack.size() != 1) {
        throw std::invalid_argument("Invalid expression");
    }

    return valueStack.top();
}

bool PostfixEvaluator::isNumber(const std::string& token) const {
    bool isValid = !token.empty();
    size_t dotCount = 0;

    for (size_t i = 0; isValid && i < token.size(); ++i) {
        if (token[i] == '.') {
            isValid = (++dotCount <= 1);
        } else {
            isValid = isdigit(token[i]) != 0;
        }
    }

    return isValid;
}

bool PostfixEvaluator::isOperator(const std::string& token) const {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool PostfixEvaluator::isUnaryOperator(const std::string& token) const {
    return token.size() == 2 && token[0] == 'u';
}

double PostfixEvaluator::applyUnaryOperator(const std::string& op, double a) {
    if (op == "u+") {
        return +a;
    } else if (op == "u-") {
        return -a;
    }
    throw std::invalid_argument("Unknown unary operator");
}

double PostfixEvaluator::applyBinaryOperator(const std::string& op, double a, double b) {
    if (op == "+") {
        return a + b;
    } else if (op == "-") {
        return a - b;
    } else if (op == "*") {
        return a * b;
    } else if (op == "/") {
        if (b == 0) {
            throw std::invalid_argument("Division by zero");
        }
        return a / b;
    }
    throw std::invalid_argument("Unknown binary operator");
}
