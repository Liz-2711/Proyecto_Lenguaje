#ifndef MEMORIA_H
#define MEMORIA_H

#include <unordered_map>
#include <string>

/*Estos archivos definen e implementan la clase Memoria,
encargada de gestionar las variables y sus valores. Las
funciones principales incluyen:

Asignar Valores a Variables: Permite al usuario asignar 
valores a variables.

Obtener Valores de Variables: Recupera el valor de una variable
para su uso en cálculos.

Verificación de Existencia de Variables: Comprueba si una 
variable ha sido definida previamente.*/

// Clase para gestionar variables y sus valores
class Memoria {
public:
    // Asigna un valor a una variable
    void asignar(const std::string& variable, double valor);

    // Obtiene el valor de una variable
    double obtener(const std::string& variable) const;

    // Verifica si una variable está definida
    bool existe(const std::string& variable) const;

private:
    std::unordered_map<std::string, double> variables; // Almacena las variables y sus valores
};

#endif // MEMORIA_H