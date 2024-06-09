#include "lexer.h"
#include "parser.h"
#include <iostream>
#include <string>
#include <vector>

Token token(std::string value, TokenType type) {
    return { value, type };
}

std::string shift(std::vector<std::string>& src) {
    std::string current = src.front();
    src.erase(src.begin());
    return current;
}

bool isNumber(const std::string& str) {
    for (char c : str) {
        if (!isdigit(c))
            return false;
    }
    return true;
}

bool isAlpha(const std::string& str) {
    for (char ch : str) {
        if (!isalpha(ch))
            return false;
    }
    return true;
}

std::vector<std::string> parse_input(std::string expression) {
    std::vector<std::string> tokens;
    std::string currentToken;
    std::string operators = "+-*/%()";
    for (size_t i = 0; i < expression.size(); ++i) {
        char c = expression[i];
        
        if (std::isspace(c)) {
            continue;
        }
        if (std::isalpha(c)) {
            currentToken += c;
        } else if (std::isdigit(c) || c == '.') {
            currentToken += c;
        } else if (operators.find(c) != std::string::npos) {
            if (!currentToken.empty()) {
                tokens.push_back(currentToken);
                currentToken.clear();
            }
            tokens.push_back(std::string(1, c));
        } else {
            std::cerr << "Caracter Inesperado: " << c << std::endl;
        }
    }

    if (!currentToken.empty()) {
        tokens.push_back(currentToken);
    }
    return tokens;
}

void tokenize(std::string expression, std::vector<Token>& tokens) {
    std::vector<std::string> src = parse_input(expression);

    while (!src.empty()) {
        if (src.front() == "+" || src.front() == "-" || src.front() == "*" || src.front() == "/" || src.front() == "%") {
            tokens.push_back(token(shift(src), TokenType::Operator));
        } 
        else if (src.front() == "(") {
            tokens.push_back(token(shift(src), TokenType::OpenParenthesis)); // Corrected spelling here
        }
        else if (src.front() == ")") {
            tokens.push_back(token(shift(src), TokenType::CloseParenthesis)); // Corrected spelling here
        }
        else {
            if (isNumber(src.front())) {
                std::string number;
                while (!src.empty() && isNumber(src.front())) {
                    number += shift(src);
                }

                tokens.push_back(token(number, TokenType::Number));
            } else if (isAlpha(src.front())) {
                std::string ident = shift(src);
                tokens.push_back(token(ident, TokenType::Variable));
            }
        }
    }
}

void lexer(std::string expression) {
    std::vector<Token> tokens;
    tokenize(expression, tokens);
}
