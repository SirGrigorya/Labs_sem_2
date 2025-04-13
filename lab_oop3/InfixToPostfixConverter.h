#ifndef INFIX_TO_POSTFIX_CONVERTER_H
#define INFIX_TO_POSTFIX_CONVERTER_H

#include <vector>
#include <string>
#include <stack>
#include <unordered_map>

class InfixToPostfixConverter {
public:
    std::vector<std::string> convert(const std::vector<std::string>& tokens);

private:
    bool isNumber(const std::string& token) const;
    bool isLeftParenthesis(const std::string& token) const;
    bool isRightParenthesis(const std::string& token) const;
    bool isOperator(const std::string& token) const;
    bool isUnaryOperator(const std::string& token) const;
    int getPrecedence(const std::string& op) const;

    const std::unordered_map<std::string, int> precedence {
        {"u+", 4}, {"u-", 4},
        {"*", 3}, {"/", 3},
        {"+", 2}, {"-", 2}
    };
};

#endif // INFIX_TO_POSTFIX_CONVERTER_H
