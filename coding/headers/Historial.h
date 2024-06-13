#ifndef HISTORIAL_H
#define HISTORIAL_H

#include <vector>
#include <string>

class Historial {
private:
    std::vector<std::string> entradas;
public:
    void agregar(const std::string& expresion, const std::string& resultado);
    void mostrar() const;
    //std::string obtenerHistorial() const; 
    std::vector<std::string> obtenerHistorial(); 
};

#endif