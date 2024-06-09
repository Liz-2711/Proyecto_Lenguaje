#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <string>
#include <vector>

// Definición del tipo TokenType
enum class TokenType {
    Number,
    Variable,
    Constant,
    Operator,
    OpenParenthesis, 
    CloseParenthesis, 
    End
};

// Estructura para representar un token
struct Token {
    std::string value;
    TokenType type;
};

// Funciones relacionadas con el análisis léxico
void tokenize(std::string expression, std::vector<Token>& tokens); // Corrected signature here
Token getToken(const std::vector<Token>& tokens, size_t& index);
Token getNextToken();
void lexer(std::string expression);

#endif // LEXER_H  
