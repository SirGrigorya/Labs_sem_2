#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <vector>
#include <string>

class Tokenizer {
public:
    std::vector<std::string> tokenize(const std::string& expression);

private:
    bool isOperator(char c) const;
    bool isUnaryOperatorExpected(bool expectUnary, const std::string& currentToken) const;
    void flushCurrentToken(std::string& currentToken, std::vector<std::string>& tokens);
};

#endif // TOKENIZER_H
