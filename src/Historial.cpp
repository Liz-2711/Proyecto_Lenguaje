#include "Historial.h"
#include <iostream>
#include <sstream>  // Incluye esta línea

void Historial::agregar(const std::string& expresion, const std::string& resultado) {
    entradas.push_back(expresion + " = " + resultado);
}

void Historial::mostrar() const {
    for (const auto& entrada : entradas) {
        std::cout << entrada << std::endl;
    }
}

std::string Historial::obtenerHistorial() const {
    std::ostringstream ss;
    for (const auto& entrada : entradas) {
        ss << entrada << std::endl;
    }
    return ss.str();
}
