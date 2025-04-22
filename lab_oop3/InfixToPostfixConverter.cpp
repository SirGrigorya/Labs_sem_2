#include "InfixToPostfixConverter.h"
#include "NumberToken.h"
#include "Token.h"
#include <stack>
#include <stdexcept>

#define ERR_MISMATCHED_PARENTHESES "Mismatched parentheses"

std::vector<std::unique_ptr<Token>> InfixToPostfixConverter::convert(const std::vector<std::unique_ptr<Token>>& tokens) {
    std::vector<std::unique_ptr<Token>> postfix;
    std::stack<std::unique_ptr<Token>> opStack;

    for (const auto& tokenPtr : tokens) {
        const Token& token = *tokenPtr;
        TokenType type = token.getType();

        if (type == TOKEN_NUMBER) {
            const NumberToken& num = dynamic_cast<const NumberToken&>(token);
            double value = num.getNumber();
            postfix.push_back(std::make_unique<NumberToken>(value));
        } else if (isUnaryOperator(token)) {
            opStack.push(cloneToken(token));
        } else if (type == TOKEN_LPAREN) {
            opStack.push(cloneToken(token));
        } else if (type == TOKEN_RPAREN) {
            while (!opStack.empty() && opStack.top()->getType() != TOKEN_LPAREN) {
                postfix.push_back(std::move(opStack.top()));
                opStack.pop();
            }

            if (opStack.empty()) {
                throw std::invalid_argument(ERR_MISMATCHED_PARENTHESES);
            }

            opStack.pop();

            if (!opStack.empty() && isUnaryOperator(*opStack.top())) {
                postfix.push_back(std::move(opStack.top()));
                opStack.pop();
            }
        } else if (isBinaryOperator(token)) {
            while (!opStack.empty() &&
                   opStack.top()->getType() != TOKEN_LPAREN &&
                   (isUnaryOperator(*opStack.top()) ||
                    getPrecedence(*opStack.top()) >= getPrecedence(token))) {
                postfix.push_back(std::move(opStack.top()));
                opStack.pop();
            }
            opStack.push(cloneToken(token));
        }
    }

    while (!opStack.empty()) {
        if (opStack.top()->getType() == TOKEN_LPAREN) {
            throw std::invalid_argument(ERR_MISMATCHED_PARENTHESES);
        }
        postfix.push_back(std::move(opStack.top()));
        opStack.pop();
    }

    return postfix;
}

bool InfixToPostfixConverter::isBinaryOperator(const Token& token) const {
    bool result = false;
    TokenType type = token.getType();

    if (type == TOKEN_PLUS || type == TOKEN_MINUS || type == TOKEN_MULTIPLY || type == TOKEN_DIVIDE) {
        result = true;
    }

    return result;
}

bool InfixToPostfixConverter::isUnaryOperator(const Token& token) const {
    bool result = false;
    TokenType type = token.getType();

    if (type == TOKEN_UNARY_PLUS || type == TOKEN_UNARY_MINUS) {
        result = true;
    }

    return result;
}

int InfixToPostfixConverter::getPrecedence(const Token& token) const {
    int precedence = 0;
    TokenType type = token.getType();

    if (type == TOKEN_UNARY_PLUS || type == TOKEN_UNARY_MINUS) {
        precedence = 3;
    } else if (type == TOKEN_MULTIPLY || type == TOKEN_DIVIDE) {
        precedence = 2;
    } else if (type == TOKEN_PLUS || type == TOKEN_MINUS) {
        precedence = 1;
    }

    return precedence;
}

std::unique_ptr<Token> InfixToPostfixConverter::cloneToken(const Token& token) {
    TokenType type = token.getType();
    std::unique_ptr<Token> result = nullptr;

    if (type == TOKEN_NUMBER) {
        const NumberToken& num = dynamic_cast<const NumberToken&>(token);
        result = std::make_unique<NumberToken>(num.getNumber());
    } else {
        result = std::make_unique<Token>(type);
    }

    return result;
}
