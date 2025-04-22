#include "Tokenizer.h"
#include <cctype>
#include <memory>
#include <stdexcept>
#include <cstdlib>
#include "Constants.h"
#include "NumberToken.h"

#define ERR_INVALID_CHAR "Invalid character in expression"

std::vector<std::unique_ptr<Token>> Tokenizer::tokenize(const std::string& expression) {
    std::vector<std::unique_ptr<Token>> tokens;
    std::string current;
    bool expectUnary = true;

    for (size_t i = 0; i < expression.length(); ++i) {
        char c = expression[i];

        if (isspace(c)) continue;

        if (isdigit(c) || c == '.') {
            current += c;
            expectUnary = false;
        } else {
            if (!current.empty()) {
                double num = std::stod(current);
                tokens.push_back(std::make_unique<NumberToken>(num));
                current.clear();
            }

            if (c == PAREN_OPEN_CHAR) {
                tokens.push_back(std::make_unique<Token>(TOKEN_LPAREN));
                expectUnary = true;
            } else if (c == PAREN_CLOSE_CHAR) {
                tokens.push_back(std::make_unique<Token>(TOKEN_RPAREN));
                expectUnary = false;
            } else if (isOperator(c)) {
                TokenType type = TOKEN_INVALID;
                if (expectUnary && (c == OP_PLUS_CHAR || c == OP_MINUS_CHAR)) {
                    type = getUnaryTokenType(c);
                } else {
                    type = getBinaryTokenType(c);
                }
                tokens.push_back(std::make_unique<Token>(type));
                expectUnary = true;
            } else {
                throw std::invalid_argument(ERR_INVALID_CHAR);
            }
        }
    }

    if (!current.empty()) {
        double num = std::stod(current);
        tokens.push_back(std::make_unique<NumberToken>(num));
    }

    return tokens;
}

bool Tokenizer::isOperator(char c) const {
    bool result = false;
    if (c == OP_PLUS_CHAR || c == OP_MINUS_CHAR ||
        c == OP_MULTIPLY_CHAR || c == OP_DIVIDE_CHAR) {
        result = true;
    }
    return result;
}

TokenType Tokenizer::getUnaryTokenType(char c) const {
    TokenType type = TOKEN_INVALID;
    if (c == OP_PLUS_CHAR) {
        type = TOKEN_UNARY_PLUS;
    } else if (c == OP_MINUS_CHAR) {
        type = TOKEN_UNARY_MINUS;
    }
    return type;
}

TokenType Tokenizer::getBinaryTokenType(char c) const {
    TokenType type = TOKEN_INVALID;
    if (c == OP_PLUS_CHAR) {
        type = TOKEN_PLUS;
    } else if (c == OP_MINUS_CHAR) {
        type = TOKEN_MINUS;
    } else if (c == OP_MULTIPLY_CHAR) {
        type = TOKEN_MULTIPLY;
    } else if (c == OP_DIVIDE_CHAR) {
        type = TOKEN_DIVIDE;
    }
    return type;
}
