#include "./headers/Evaluador.h"
#include "./headers/EvaluadorPostFijas.h"
#include "./headers/Conversor.h"

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <sstream>
#include <stack>

std::string Evaluador::evaluar(const std::vector<Token>& expresion, Memoria& memoria, Configuracion& configuracion) {
    std::stack<Token> expresionPostfija = infijaAPostfija(expresion); 

    double resultado = evaluarPostfija(expresionPostfija);
    std::ostringstream ss;
    ss << resultado;
    return ss.str();
}
