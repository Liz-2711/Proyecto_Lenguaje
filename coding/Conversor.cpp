
#include "./headers/Conversor.h"
#include <stack>
#include <string>
#include <unordered_map>

std::stack<Token> infijaAPostfija(const std::vector<Token>& expresion) {
    for (Token t : expresion) {
        cout << "Valor" << t.value << endl;
    }
    std::stack<Token> salida;
    std::stack<Token> operadores;
    std::unordered_map<std::string, int> precedencia = {
        {"+", 1}, {"-", 1},
        {"*", 2}, {"/", 2}, {"%", 2},
        {"^", 3}
    };

    for (const Token& token : expresion) {
        if (token.type == TokenType::Number || token.type == TokenType::Variable || token.type == TokenType::Constant) {
            salida.push(token);
        } else if (token.type == TokenType::OpenParentesis) {
            operadores.push(token);
        } else if (token.type == TokenType::CloseParentesis) {
            while (!operadores.empty() && operadores.top().type != TokenType::OpenParentesis) {
                salida.push(operadores.top());
                operadores.pop();
            }
            if (!operadores.empty()) {
                operadores.pop();
            }
        } else if (token.type == TokenType::Operator) {
            while (!operadores.empty() && operadores.top().type == TokenType::Operator &&
                   precedencia[token.value] <= precedencia[operadores.top().value]) {
                salida.push(operadores.top());
                operadores.pop();
            }
            operadores.push(token);
        }
    }

    while (!operadores.empty()) {
        salida.push(operadores.top());
        operadores.pop();
    }

    return salida;
}