#include "Memoria.h"
#include <stdexcept>

void Memoria::asignar(const std::string& variable, double valor) {
    variables[variable] = valor;
}

double Memoria::obtener(const std::string& variable) const {
    if (!existe(variable)) {
        throw std::invalid_argument("Variable no definida: " + variable);
    }
    return variables.at(variable);
}

bool Memoria::existe(const std::string& variable) const {
    return variables.find(variable) != variables.end();
}
