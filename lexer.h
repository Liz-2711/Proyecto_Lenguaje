#pragma once

#ifndef  LEXER_H
#define LEXER_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum TokenType {
    Number,
    Variable,
    Constant,
    Operator,
    OpenParentesis,
    CloseParentesis,
    End
};

struct Token {
    std::string value;
    TokenType type;
};

extern vector<Token> tokens;

Token getToken();

Token getNextToken();

void lexer(string expression);

#endif