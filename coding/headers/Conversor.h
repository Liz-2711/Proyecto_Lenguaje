#ifndef CONVERSOR_H
#define CONVERSOR_H

#include <string>
#include "lexer.h"
#include <stack>

//std::string infijaAPostfija(const std::string& expresion);
std::stack<Token> infijaAPostfija(const std::vector<Token>& expresion);

#endif 