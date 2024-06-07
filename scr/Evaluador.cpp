#include "Evaluador.h"
#include <stack>
#include <stdexcept>
#include <sstream>
#include <cmath>

std::string Evaluador::evaluar(const std::string& expresion, Memoria& memoria, Configuracion& configuracion) {
    std::string postfija = infijaAPostfija(expresion);
    double resultado = evaluarPostfija(postfija, memoria, configuracion);
    std::ostringstream ss;
    ss << resultado;
    return ss.str();
}

std::string Evaluador::infijaAPostfija(const std::string& expresion) {
    // Implementación de conversión de infija a postfija
    // ...
/*Inicialización:

Se usa una pila (pila) para gestionar los operadores.
La cadena postfija almacenará la expresión en notación postfija.
La variable puedeHaberOperador ayuda a validar la posición 
correcta de operadores.*/


    std::   stack<char> pila;
    std::string postfija;
    bool puedeHaberOperador = false; // Evitar expresiones incorrectas como "10+5+."

    for (size_t i = 0; i < expresion.length(); ++i) {
        char c = expresion[i];

        // Ignorar espacios en blanco
        if (isspace(c)) {
            continue;
        }

        // Si es un número o una letra (variable), añadirlo a la salida
        if (isdigit(c) || isalpha(c)) {
            postfija += c;
            puedeHaberOperador = true; // Después de un número/variable puede haber un operador
        }


/*Recorrido de la expresión:

Espacios en blanco: Son ignorados.
Números o variables: Se añaden directamente a postfija.

Paréntesis izquierdos ((): Se añaden a la pila.

Paréntesis derechos ()): Se sacan operadores de la pila
 hasta encontrar un paréntesis izquierdo.

Operadores: Se sacan operadores de la pila con mayor o 
igual precedencia y se añaden a postfija, luego el operador
 actual se añade a la pila.*/


        // Si es un paréntesis izquierdo, añadirlo a la pila
        else if (c == '(') {
            pila.push(c);
            puedeHaberOperador = false; // No puede haber un operador después de un '('
        }
        // Si es un paréntesis derecho, sacar de la pila hasta encontrar el paréntesis izquierdo
        else if (c == ')') {
            while (!pila.empty() && pila.top() != '(') {
                postfija += pila.top();
                pila.pop();
            }
            if (pila.empty()) {
                throw std::invalid_argument("Paréntesis desbalanceados");
            }
            pila.pop(); // Sacar el paréntesis izquierdo
            puedeHaberOperador = true; // Después de un ')' puede haber un operador
        }
        // Si es un operador
        else if (esOperador(c)) {
            if (!puedeHaberOperador) {
                throw std::invalid_argument("Expresión inválida: operador en una posición incorrecta");
            }
            while (!pila.empty() && esOperador(pila.top()) && precedencia(pila.top()) >= precedencia(c)) {
                postfija += pila.top();
                pila.pop();
            }
            pila.push(c);
            puedeHaberOperador = false; // Después de un operador no puede haber otro operador inmediatamente
        } else {
            throw std::invalid_argument("Carácter inválido en la expresión");
        }
    }

    // Sacar todos los operadores restantes de la pila
    while (!pila.empty()) {
        if (pila.top() == '(') {
            throw std::invalid_argument("Paréntesis desbalanceados");
        }
        postfija += pila.top();
        pila.pop();
    }

    return postfija;
}

double Evaluador::evaluarPostfija(const std::string& expresion, Memoria& memoria, Configuracion& configuracion) {
    // Implementación de evaluación de expresión postfija
    std::stack<double> pila;
/*nicialización:

Se usa una pila (pila) para gestionar los números y resultados intermedios.*/


    for (size_t i = 0; i < expresion.length(); ++i) {
        char c = expresion[i];

        if (isspace(c)) {
            continue;
        }
/* Recorrido de la expresión postfija:

Espacios en blanco: Son ignorados.
Números: Se agrupan y se convierten a double utilizando 
std::stod antes de ser empujados a la pila.

Variables: Se agrupan y se verifican en Memoria y Configuracion.
 Si la variable existe, su valor se empuja a la pila.

Operadores: Se sacan los dos operandos de la pila, se aplica el 
operador y el resultado se empuja de nuevo a la pila.*/


        if (isdigit(c)) {
            std::string numero;
            while (i < expresion.length() && (isdigit(expresion[i]) || expresion[i] == '.')) {
                numero += expresion[i];
                ++i;
            }
            --i; // Ajustar porque el último incremento no corresponde a un dígito
            pila.push(std::stod(numero));
        }
        else if (isalpha(c)) {
            std::string variable;
            while (i < expresion.length() && isalpha(expresion[i])) {
                variable += expresion[i];
                ++i;
            }
            --i; // Ajustar porque el último incremento no corresponde a una letra
            if (memoria.existe(variable)) {
                pila.push(memoria.obtener(variable));
            } else if (configuracion.existe(variable)) {
                pila.push(configuracion.obtener(variable));
            } else {
                throw std::invalid_argument("Variable no definida: " + variable);
            }
        }
        else if (esOperador(c)) {
            if (pila.size() < 2) {
                throw std::invalid_argument("Expresión postfija inválida");
            }
            double op2 = pila.top(); pila.pop();
            double op1 = pila.top(); pila.pop();
            double resultado;

            switch (c) {
                case '+': resultado = op1 + op2; break;
                case '-': resultado = op1 - op2; break;
                case '*': resultado = op1 * op2; break;
                case '/': 
                    if (op2 == 0) {
                        throw std::invalid_argument("División por cero");
                    }
                    resultado = op1 / op2; 
                    break;
                case '^': resultado = pow(op1, op2); break;
                default: throw std::invalid_argument("Operador desconocido");
            }
            pila.push(resultado);
        } else {
            throw std::invalid_argument("Carácter inválido en la expresión postfija");
        }
    }

    if (pila.size() != 1) {
        throw std::invalid_argument("Expresión postfija inválida");
    }

/*Validaciones:

Se valida que haya suficientes operandos en la pila para cada operador.
Se valida que no se intente una división por cero.
Al final, la pila debe contener exactamente un elemento, que es 
el resultado de la expresión.*/

    return pila.top();
}

bool Evaluador::esOperador(char c) {
    // Implementación para verificar si el caracter es un operador
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int Evaluador::precedencia(char operador) {
    // Implementación para obtener la precedencia de un operador
    switch (operador) {
        case '^':
            return 3;
        case '*': case '/': case '%':
            return 2;
        case '+': case '-':
            return 1;
        default:
            return 0;
    }
}
