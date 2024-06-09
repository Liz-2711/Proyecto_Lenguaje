#include "Conversor.h"
#include <stack>
#include <string>
#include <unordered_map>

std::string infijaAPostfija(const std::string& expresion) {
    std::stack<char> pila;
    std::string postfija;
    std::unordered_map<char, int> precedencia = {
        {'+', 1}, {'-', 1},
        {'*', 2}, {'/', 2}, {'%', 2},
        {'^', 3}
    };

    for (char c : expresion) {
        if (std::isalnum(c)) {
            postfija += c;
        } else if (c == '(') {
            pila.push(c);
        } else if (c == ')') {
            while (!pila.empty() && pila.top() != '(') {
                postfija += pila.top();
                pila.pop();
            }
            pila.pop(); // Eliminar '(' de la pila
        } else {
            while (!pila.empty() && precedencia[c] <= precedencia[pila.top()]) {
                postfija += pila.top();
                pila.pop();
            }
            pila.push(c);
        }
    }

    while (!pila.empty()) {
        postfija += pila.top();
        pila.pop();
    }

    return postfija;
}

