#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <memory>
#include <vector>
#include <string>
#include "Token.h"

class Tokenizer {
public:
    std::vector<std::unique_ptr<Token>> tokenize(const std::string& expression);

private:
    bool isOperator(char c) const;
    TokenType getUnaryTokenType(char c) const;
    TokenType getBinaryTokenType(char c) const;
};

#endif // TOKENIZER_H
