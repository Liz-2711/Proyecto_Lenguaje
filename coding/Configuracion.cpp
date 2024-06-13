#include "./headers/Configuracion.h"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

Configuracion::Configuracion(const std::string& archivo) {
    cargarArchivo(archivo);
}

void Configuracion::cargarArchivo(const std::string& archivo) {
    std::ifstream file(archivo);
    if (!file) {
        throw std::invalid_argument("No se pudo abrir el archivo de configuracion: " + archivo);
    }

    std::string linea;
    while (std::getline(file, linea)) {
        std::istringstream ss(linea);
        std::string nombre;
        double valor;
        if (std::getline(ss, nombre, '=') && ss >> valor) {
            constantes[nombre] = valor;
            std::cout << nombre << " - " << valor << std::endl;
        }
    }
}

double Configuracion::obtener(const std::string& constante) const {
    if (!existe(constante)) {
       // throw std::invalid_argument("Constante no definida: " + constante);
       return NULL;
    }
    return constantes.at(constante);
}

bool Configuracion::existe(const std::string& constante) const {
    return constantes.find(constante) != constantes.end();
}

std::unordered_map<std::string, double> Configuracion::obtenerConstantes()
{
    return constantes;
}
