#ifndef HISTORIAL_H
#define HISTORIAL_H

#include <vector>
#include <string>

/*
Estos archivos definen e implementan la clase 
Historial, que almacena el historial de operaciones 
realizadas. Las funciones principales son:

Agregar al Historial: Guarda cada expresión y su resultado.
Mostrar Historial: Imprime todas las entradas del historial,
 permitiendo al usuario revisar operaciones anteriores.
*/




class Historial {
private:
    std::vector<std::string> entradas;
public:
    void agregar(const std::string& expresion, const std::string& resultado);
    void mostrar() const;
    std::string obtenerHistorial() const; // Añade esta línea
};

#endif // HISTORIAL_H
