#include "./headers/EvaluadorPostFijas.h"
#include <stack>
#include <string>
#include <iostream>

double evaluarPostfija(std::stack<Token> tokens) {
    std::stack<double> pila;

    std::stack<Token> tempStack;
    while (!tokens.empty()) {
        tempStack.push(tokens.top());
        tokens.pop();
    }

    while (!tempStack.empty()) {
        Token token = tempStack.top();
        tempStack.pop();

        if (token.type == TokenType::Number || token.type == TokenType::Constant) {
            pila.push(std::stod(token.value)); 
        }

        else if (token.type == TokenType::Operator) {
            double operando2 = pila.top();
            pila.pop();
            double operando1 = pila.top();
            pila.pop();

            if (token.value == "+") {
                pila.push(operando1 + operando2);
            } else if (token.value == "-") {
                pila.push(operando1 - operando2);
            } else if (token.value == "*") {
                pila.push(operando1 * operando2);
            } else if (token.value == "/") {
                pila.push(operando1 / operando2);
            }
        }
    }

    return pila.top();
}