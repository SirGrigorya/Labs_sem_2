#include "Tokenizer.h"
#include <cctype>
#include <stdexcept>

// Operator and symbol definitions
#define OP_PLUS          '+'
#define OP_MINUS         '-'
#define OP_MULTIPLY      '*'
#define OP_DIVIDE        '/'
#define PAREN_OPEN       '('
#define PAREN_CLOSE      ')'
#define UNARY_PREFIX     "u"

#define ERR_INVALID_CHAR "Invalid character in expression"

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

            if (c == '(') {
                tokens.push_back(std::string(1, c));
                expectUnary = true;
            } else if (c == ')') {
                tokens.push_back(std::string(1, c));
                expectUnary = false;
            } else if (isOperator(c)) {
                if (expectUnary && (c == '+' || c == '-')) {
                    tokens.push_back(std::string("u") + c);
                } else {
                    tokens.push_back(std::string(1, c));
                }
                expectUnary = true;
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
    return c == OP_PLUS || c == OP_MINUS || c == OP_MULTIPLY || c == OP_DIVIDE;
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
