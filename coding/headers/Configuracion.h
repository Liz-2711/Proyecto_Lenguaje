
#ifndef CONFIGURACION_H
#define CONFIGURACION_H

#include <unordered_map>
#include <string>
#include <vector>


class Configuracion {
public:
    Configuracion(const std::string& archivo);

    double obtener(const std::string& constante) const;

    bool existe(const std::string& constante) const;

    std::unordered_map<std::string, double> obtenerConstantes();

private:
    std::unordered_map<std::string, double> constantes;
    void cargarArchivo(const std::string& archivo);
};

#endif