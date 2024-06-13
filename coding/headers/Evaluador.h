#ifndef EVALUADOR_H
#define EVALUADOR_H

#include <string>
#include <vector>
#include "lexer.h"
#include "parser.h"

class Memoria;
class Configuracion;

class Evaluador {
public:
    std::string evaluar(const std::vector<Token>& expresion, Memoria& memoria, Configuracion& configuracion);
    //bool validar(const std::string& expresion);
};

#endif