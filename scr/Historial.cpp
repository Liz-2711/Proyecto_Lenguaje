#include "Historial.h"
#include <iostream>

void Historial::agregar(const std::string& expresion, const std::string& resultado) {
    entradas.push_back(expresion + " = " + resultado);

}

void Historial::mostrar() const {
    for (const auto& entrada : entradas) {
        std::cout << entrada << std::endl;
        
    }
}
