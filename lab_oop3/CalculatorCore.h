// CalculatorCore.h
#ifndef CALCULATORCORE_H
#define CALCULATORCORE_H

#include <string>
#include <vector>
#include <stack>
#include <map>
#include <stdexcept>

class CalculatorCore {
public:
    CalculatorCore();
    double calculate(const std::string& expression);

private:
    std::vector<std::string> tokenize(const std::string& expression);
    std::vector<std::string> infixToPostfix(const std::vector<std::string>& tokens);
    double evaluatePostfix(const std::vector<std::string>& postfix);

    bool isOperator(const std::string& token) const;
    bool isNumber(const std::string& token) const;
    bool isLeftParenthesis(const std::string& token) const;
    bool isRightParenthesis(const std::string& token) const;

    int getPrecedence(const std::string& op) const;

    std::map<std::string, int> precedence = {
        {"+", 1}, {"-", 1},
        {"*", 2}, {"/", 2}
    };
};

#endif // CALCULATORCORE_H
