#ifndef CONFIGURACION_H
#define CONFIGURACION_H

#include <unordered_map>
#include <string>


/*Estos archivos definen e implementan la clase 
Configuracion, que maneja la carga y gestión de 
constantes desde un archivo de configuración. Sus funciones son:

Cargar Constantes: Lee las constantes definidas en 
un archivo y las almacena.

Obtener Constantes: Recupera el valor de una constante
 para su uso en cálculos.

Verificación de Existencia de Constantes: Comprueba si 
una constante está definida en el archivo de configuración.*/

class Configuracion {
public:
    Configuracion(const std::string& archivo);
    double obtener(const std::string& constante) const;
    bool existe(const std::string& constante) const;
private:
    std::unordered_map<std::string, double> constantes;
    void cargarArchivo(const std::string& archivo);
};

#endif // CONFIGURACION_H
