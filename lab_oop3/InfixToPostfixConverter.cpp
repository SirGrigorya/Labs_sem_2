#include "InfixToPostfixConverter.h"
#include <stack>
#include <stdexcept>
#include <cctype>

std::vector<std::string> InfixToPostfixConverter::convert(const std::vector<std::string>& tokens) {
    std::vector<std::string> postfix;
    std::stack<std::string> opStack;

    for (const auto& token : tokens) {
        if (isNumber(token)) {
            postfix.push_back(token);
        } else if (isUnaryOperator(token)) {
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

bool InfixToPostfixConverter::isNumber(const std::string& token) const {
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

bool InfixToPostfixConverter::isLeftParenthesis(const std::string& token) const {
    return token == "(";
}

bool InfixToPostfixConverter::isRightParenthesis(const std::string& token) const {
    return token == ")";
}

bool InfixToPostfixConverter::isOperator(const std::string& token) const {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool InfixToPostfixConverter::isUnaryOperator(const std::string& token) const {
    return token.size() == 2 && token[0] == 'u';
}

int InfixToPostfixConverter::getPrecedence(const std::string& op) const {
    auto it = precedence.find(op);
    return it != precedence.end() ? it->second : 0;
}
