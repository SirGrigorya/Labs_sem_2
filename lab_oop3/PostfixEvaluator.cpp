#include "PostfixEvaluator.h"
#include <stdexcept>
#include <cctype>

#define OP_PLUS          "+"
#define OP_MINUS         "-"
#define OP_MULTIPLY      "*"
#define OP_DIVIDE        "/"
#define UNARY_PLUS       "u+"
#define UNARY_MINUS      "u-"

#define ERR_INVALID_UNARY_OP    "Invalid unary operator usage"
#define ERR_INVALID_EXPRESSION  "Invalid expression"
#define ERR_UNKNOWN_UNARY_OP    "Unknown unary operator"
#define ERR_DIVISION_BY_ZERO    "Division by zero"
#define ERR_UNKNOWN_BINARY_OP   "Unknown binary operator"

double PostfixEvaluator::evaluate(const std::vector<std::string>& postfix) {
    std::stack<double> valueStack;

    for (const auto& token : postfix) {
        if (isNumber(token)) {
            valueStack.push(std::stod(token));
        }
        else if (isUnaryOperator(token)) {
            if (valueStack.empty()) {
                throw std::invalid_argument(ERR_INVALID_UNARY_OP);
            }
            double a = valueStack.top(); valueStack.pop();
            valueStack.push(applyUnaryOperator(token, a));
        }
        else if (isOperator(token)) {
            if (valueStack.size() < 2) {
                throw std::invalid_argument(ERR_INVALID_EXPRESSION);
            }
            double b = valueStack.top(); valueStack.pop();
            double a = valueStack.top(); valueStack.pop();
            valueStack.push(applyBinaryOperator(token, a, b));
        }
    }

    if (valueStack.size() != 1) {
        throw std::invalid_argument(ERR_INVALID_EXPRESSION);
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
    bool result = (token == OP_PLUS || token == OP_MINUS ||
                   token == OP_MULTIPLY || token == OP_DIVIDE);
    return result;
}

bool PostfixEvaluator::isUnaryOperator(const std::string& token) const {
    bool result = (token == UNARY_PLUS || token == UNARY_MINUS);
    return result;
}

double PostfixEvaluator::applyUnaryOperator(const std::string& op, double a) {
    double result = 0.0;

    if (op == UNARY_PLUS) {
        result = +a;
    } else if (op == UNARY_MINUS) {
        result = -a;
    } else {
        throw std::invalid_argument(ERR_UNKNOWN_UNARY_OP);
    }

    return result;
}

double PostfixEvaluator::applyBinaryOperator(const std::string& op, double a, double b) {
    double result = 0.0;

    if (op == OP_PLUS) {
        result = a + b;
    } else if (op == OP_MINUS) {
        result = a - b;
    } else if (op == OP_MULTIPLY) {
        result = a * b;
    } else if (op == OP_DIVIDE) {
        if (b == 0) {
            throw std::invalid_argument(ERR_DIVISION_BY_ZERO);
        }
        result = a / b;
    } else {
        throw std::invalid_argument(ERR_UNKNOWN_BINARY_OP);
    }

    return result;
}
