#include "PostfixEvaluator.h"
#include <stdexcept>
#include "Constants.h"
#include "NumberToken.h"

#define ERR_INVALID_UNARY_OP    "Invalid unary operator usage"
#define ERR_INVALID_EXPRESSION  "Invalid expression"
#define ERR_UNKNOWN_UNARY_OP    "Unknown unary operator"
#define ERR_DIVISION_BY_ZERO    "Division by zero"
#define ERR_UNKNOWN_BINARY_OP   "Unknown binary operator"
#define ERR_NUMBER_CAST_FAILED  "Invalid number token"

double PostfixEvaluator::evaluate(const std::vector<std::unique_ptr<Token>>& postfix) {
    std::stack<double> valueStack;

    for (const auto& tokenPtr : postfix) {
        const Token& token = *tokenPtr;
        TokenType type = token.getType();

        if (type == TOKEN_NUMBER) {
            const NumberToken* numToken = dynamic_cast<const NumberToken*>(&token);
            if (!numToken) {
                throw std::runtime_error(ERR_NUMBER_CAST_FAILED);
            }
            double value = numToken->getNumber();
            valueStack.push(value);
        } else if (isUnaryOperator(token)) {
            if (valueStack.empty()) {
                throw std::invalid_argument(ERR_INVALID_UNARY_OP);
            }
            double a = valueStack.top();
            valueStack.pop();
            double result = applyUnaryOperator(token, a);
            valueStack.push(result);
        } else if (isBinaryOperator(token)) {
            if (valueStack.size() < 2) {
                throw std::invalid_argument(ERR_INVALID_EXPRESSION);
            }
            double b = valueStack.top();
            valueStack.pop();
            double a = valueStack.top();
            valueStack.pop();
            double result = applyBinaryOperator(token, a, b);
            valueStack.push(result);
        }
    }

    if (valueStack.size() != 1) {
        throw std::invalid_argument(ERR_INVALID_EXPRESSION);
    }

    double result = valueStack.top();
    return result;
}

bool PostfixEvaluator::isUnaryOperator(const Token& token) const {
    bool result = false;
    TokenType type = token.getType();

    if (type == TOKEN_UNARY_PLUS || type == TOKEN_UNARY_MINUS) {
        result = true;
    }

    return result;
}

bool PostfixEvaluator::isBinaryOperator(const Token& token) const {
    bool result = false;
    TokenType type = token.getType();

    if (type == TOKEN_PLUS || type == TOKEN_MINUS || type == TOKEN_MULTIPLY || type == TOKEN_DIVIDE) {
        result = true;
    }

    return result;
}

double PostfixEvaluator::applyUnaryOperator(const Token& token, double a) {
    double result = 0.0;
    TokenType type = token.getType();

    if (type == TOKEN_UNARY_PLUS) {
        result = +a;
    } else if (type == TOKEN_UNARY_MINUS) {
        result = -a;
    } else {
        throw std::invalid_argument(ERR_UNKNOWN_UNARY_OP);
    }

    return result;
}

double PostfixEvaluator::applyBinaryOperator(const Token& token, double a, double b) {
    double result = 0.0;
    TokenType type = token.getType();

    if (type == TOKEN_PLUS) {
        result = a + b;
    } else if (type == TOKEN_MINUS) {
        result = a - b;
    } else if (type == TOKEN_MULTIPLY) {
        result = a * b;
    } else if (type == TOKEN_DIVIDE) {
        if (b == 0) {
            throw std::invalid_argument(ERR_DIVISION_BY_ZERO);
        }
        result = a / b;
    } else {
        throw std::invalid_argument(ERR_UNKNOWN_BINARY_OP);
    }

    return result;
}
