#ifndef EVALUADORPOSTFIJAS_H
#define EVALUADORPOSTFIJAS_H

#include <string>
#include <stack>
#include "lexer.h"

//double evaluarPostfija(const std::string& expresion);
double evaluarPostfija(const std::stack<Token> tokens);

#endif 