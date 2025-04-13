#include "Tokenizer.h"
#include <cctype>
#include <stdexcept>

std::vector<std::string> Tokenizer::tokenize(const std::string& expression) {
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

            if (isOperator(c) || c == '(' || c == ')') {
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

bool Tokenizer::isOperator(char c) const {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool Tokenizer::isUnaryOperatorExpected(bool expectUnary, const std::string& currentToken) const {
    return expectUnary && currentToken.empty();
}

void Tokenizer::flushCurrentToken(std::string& currentToken, std::vector<std::string>& tokens) {
    if (!currentToken.empty()) {
        tokens.push_back(currentToken);
        currentToken.clear();
    }
}
