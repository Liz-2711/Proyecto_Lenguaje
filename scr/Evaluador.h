#ifndef EVALUADOR_H
#define EVALUADOR_H

#include <string>
#include "Memoria.h"
#include "Configuracion.h"

/*Estos archivos definen e implementan la clase Evaluador, 
que tiene las siguientes responsabilidades:

Validación de Expresiones: Verifica que las expresiones 
ingresadas por el usuario sean correctas.


Conversión de Expresiones: Convierte las expresiones 
de notación infija a notación postfija para facilitar su evaluación.


Evaluación de Expresiones: Evalúa las expresiones en 
notación postfija y devuelve el resultado.*/
class Evaluador {
public:
    std::string evaluar(const std::string& expresion, Memoria& memoria, Configuracion& configuracion);
private:
    std::string infijaAPostfija(const std::string& expresion);
    double evaluarPostfija(const std::string& expresion, Memoria& memoria, Configuracion& configuracion);
    bool esOperador(char c);
    int precedencia(char operador);
};

#endif // EVALUADOR_H
