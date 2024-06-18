#pragma once

#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include "lexer.h" // Incluir lexer.h para definir Token y TokenType

extern Token currentToken;
extern Token nextToken;
extern std::vector<std::string> errors;

void expression_list(const std::vector<Token>& tokens);
void expression(const std::vector<Token>& tokens, size_t& index);

#endif