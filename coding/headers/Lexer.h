#pragma once

#ifndef  LEXER_H
#define LEXER_H

#include <iostream>
#include <string>
#include <vector>
#include "configuracion.h"
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
extern vector<Token> tokensTemp;

Token getToken();

Token getNextToken();

string lexer(string expression, Configuracion configuracion);

#endif