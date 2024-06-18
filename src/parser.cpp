#include "parser.h"
#include <iostream>

Token currentToken;
Token nextToken;
std::vector<std::string> errors;

// Inicio: OpenParenthesis, Number, Variable, Constant
// OpenParenthesis -> Number, Variable, Contant
// Number, Variable, Constant -> Operator, ClosedParenthesis
// ClosedParenthesis -> Operator
// Operator -> OpenParenthesis, Number, Variable, Constant

//vector<string> errors;

Token getToken(const std::vector<Token>& tokens, size_t& index) {
    if (index < tokens.size()) {
        return tokens[index++];
    } else {
        return Token{"", TokenType::End};
    }
}

void expression(const std::vector<Token>& tokens, size_t& index) {
    if (currentToken.type == TokenType::Number || currentToken.type == TokenType::Variable || currentToken.type == TokenType::Constant) {
        currentToken = getToken(tokens, index);
        if (currentToken.type == TokenType::Operator) {
            currentToken = getToken(tokens, index);
            expression(tokens, index);
        } else if (currentToken.type == TokenType::CloseParenthesis) {
            return;
        } else if (currentToken.type == TokenType::End) {
            return;
        } else {
            errors.push_back("Token invalido " + currentToken.value);
            std::cout << "Error de Sintaxis: Token inválido " << currentToken.value << std::endl;
        }
    } else if (currentToken.type == TokenType::OpenParenthesis) {
        currentToken = getToken(tokens, index);
        expression(tokens, index);
        if (currentToken.type == TokenType::CloseParenthesis) {
            currentToken = getToken(tokens, index);
            if (currentToken.type == TokenType::Operator) {
                currentToken = getToken(tokens, index);
                expression(tokens, index);
            } else if (currentToken.type == TokenType::End) {
                return;
            } else {
                errors.push_back("Token invalido " + currentToken.value);
                std::cout << "Error de Sintaxis: Token inválido " << currentToken.value << std::endl;
            }
        } else {
            errors.push_back("Token invalido " + currentToken.value);
            std::cout << "Error de Sintaxis: Token inválido " << currentToken.value << std::endl;
        }
    }
}

void expression_list(const std::vector<Token>& tokens) {
    size_t index = 0;
    currentToken = getToken(tokens, index);
    while (currentToken.type != TokenType::End) {
        expression(tokens, index);
    }
}