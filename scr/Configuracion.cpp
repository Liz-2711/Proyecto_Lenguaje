#include "Configuracion.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

Configuracion::Configuracion(const std::string& archivo) {
    cargarArchivo(archivo);
}

void Configuracion::cargarArchivo(const std::string& archivo) {
    std::ifstream file(archivo);
    if (!file) {
        throw std::invalid_argument("No se pudo abrir el archivo de configuración: " + archivo);
    }

    std::string linea;
    while (std::getline(file, linea)) {
        std::istringstream ss(linea);
        std::string nombre;
        double valor;
        if (ss >> nombre >> valor) {
            constantes[nombre] = valor;
        }
    }
}

double Configuracion::obtener(const std::string& constante) const {
    if (!existe(constante)) {
        throw std::invalid_argument("Constante no definida: " + constante);
    }
    return constantes.at(constante);
}

bool Configuracion::existe(const std::string& constante) const {
    return constantes.find(constante) != constantes.end();
}
