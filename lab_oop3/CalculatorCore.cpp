#include "CalculatorCore.h"
#include <cmath>
#include <cctype>
#include <stdexcept>

CalculatorCore::CalculatorCore() {}

double CalculatorCore::calculate(const std::string& expression) {
    if (expression.empty()) {
        throw std::invalid_argument("Empty expression");
    }

    auto tokens = tokenize(expression);
    auto postfix = infixToPostfix(tokens);
    return evaluatePostfix(postfix);
}

std::vector<std::string> CalculatorCore::tokenize(const std::string& expression) {
    std::vector<std::string> tokens;
    std::string currentToken;
    bool expectUnary = true;

    for (size_t i = 0; i < expression.size(); ++i) {
        char c = expression[i];

        if (isspace(c)) {
            continue;
        }

        if (isdigit(c) || c == '.') {
            currentToken += c;
            expectUnary = false;
        } else {
            if (!currentToken.empty()) {
                tokens.push_back(currentToken);
                currentToken.clear();
            }

            if (isOperator(std::string(1, c)) || c == '(' || c == ')') {
                if ((c == '+' || c == '-') && expectUnary) {
                    tokens.push_back(std::string(1, 'u') + c);
                } else {
                    tokens.push_back(std::string(1, c));
                }
                expectUnary = (c == '(');
            } else {
                throw std::invalid_argument("Invalid character in expression");
            }
        }
    }

    if (!currentToken.empty()) {
        tokens.push_back(currentToken);
    }

    return tokens;
}

std::vector<std::string> CalculatorCore::infixToPostfix(const std::vector<std::string>& tokens) {
    std::vector<std::string> postfix;
    std::stack<std::string> opStack;

    for (const auto& token : tokens) {
        if (isNumber(token)) {
            postfix.push_back(token);
        } else if (token.size() == 2 && token[0] == 'u') {
            opStack.push(token);
        } else if (isLeftParenthesis(token)) {
            opStack.push(token);
        } else if (isRightParenthesis(token)) {
            while (!opStack.empty() && !isLeftParenthesis(opStack.top())) {
                postfix.push_back(opStack.top());
                opStack.pop();
            }

            if (opStack.empty()) {
                throw std::invalid_argument("Mismatched parentheses");
            }

            opStack.pop();
        } else if (isOperator(token)) {
            while (!opStack.empty() && isOperator(opStack.top()) &&
                   getPrecedence(opStack.top()) >= getPrecedence(token)) {
                postfix.push_back(opStack.top());
                opStack.pop();
            }
            opStack.push(token);
        }
    }

    while (!opStack.empty()) {
        if (isLeftParenthesis(opStack.top())) {
            throw std::invalid_argument("Mismatched parentheses");
        }
        postfix.push_back(opStack.top());
        opStack.pop();
    }

    return postfix;
}

double CalculatorCore::evaluatePostfix(const std::vector<std::string>& postfix) {
    std::stack<double> valueStack;

    for (const auto& token : postfix) {
        if (isNumber(token)) {
            valueStack.push(std::stod(token));
        } else if (token.size() == 2 && token[0] == 'u') {
            if (valueStack.empty()) {
                throw std::invalid_argument("Invalid unary operator usage");
            }

            double a = valueStack.top(); valueStack.pop();
            if (token == "u+") {
                valueStack.push(+a);
            } else if (token == "u-") {
                valueStack.push(-a);
            }
        } else if (isOperator(token)) {
            if (valueStack.size() < 2) {
                throw std::invalid_argument("Invalid expression");
            }

            double b = valueStack.top(); valueStack.pop();
            double a = valueStack.top(); valueStack.pop();

            if (token == "+") {
                valueStack.push(a + b);
            } else if (token == "-") {
                valueStack.push(a - b);
            } else if (token == "*") {
                valueStack.push(a * b);
            } else if (token == "/") {
                if (b == 0) {
                    throw std::invalid_argument("Division by zero");
                }
                valueStack.push(a / b);
            }
        }
    }

    if (valueStack.size() != 1) {
        throw std::invalid_argument("Invalid expression");
    }

    return valueStack.top();
}

bool CalculatorCore::isOperator(const std::string& token) const {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool CalculatorCore::isNumber(const std::string& token) const {
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

bool CalculatorCore::isLeftParenthesis(const std::string& token) const {
    return token == "(";
}

bool CalculatorCore::isRightParenthesis(const std::string& token) const {
    return token == ")";
}

int CalculatorCore::getPrecedence(const std::string& op) const {
    auto it = precedence.find(op);
    return it != precedence.end() ? it->second : 0;
}
