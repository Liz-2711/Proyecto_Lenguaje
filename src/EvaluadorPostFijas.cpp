#include "EvaluadorPostFijas.h"
#include <stack>
#include <string>

double evaluarPostfija(const std::string& expresion) {
    std::stack<double> pila;

    for (char c : expresion) {
        if (std::isdigit(c)) {
            pila.push(c - '0');
        } else {
            double operando2 = pila.top();
            pila.pop();
            double operando1 = pila.top();
            pila.pop();

            switch (c) {
                case '+': pila.push(operando1 + operando2); break;
                case '-': pila.push(operando1 - operando2); break;
                case '*': pila.push(operando1 * operando2); break;
                case '/': pila.push(operando1 / operando2); break;
                // Agrega más casos para otros operadores
            }
        }
    }

    return pila.top();
}
