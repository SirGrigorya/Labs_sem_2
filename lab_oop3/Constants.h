#ifndef CONSTANTS_H
#define CONSTANTS_H

#define UNARY_PLUS       "u+"
#define UNARY_MINUS      "u-"
#define OP_PLUS          "+"
#define OP_MINUS         "-"
#define OP_MULTIPLY      "*"
#define OP_DIVIDE        "/"
#define UNARY_PREFIX     "u"
#define PAREN_OPEN       "("
#define PAREN_CLOSE      ")"

enum OperatorChar {
    OP_PLUS_CHAR        = '+',
    OP_MINUS_CHAR       = '-',
    OP_MULTIPLY_CHAR    = '*',
    OP_DIVIDE_CHAR      = '/',
    PAREN_OPEN_CHAR     = '(',
    PAREN_CLOSE_CHAR    = ')'
};

enum TokenType {
    TOKEN_NUMBER,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,
    TOKEN_UNARY_PLUS,
    TOKEN_UNARY_MINUS,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_INVALID
};

#endif // CONSTANTS_H
