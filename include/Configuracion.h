

/*Estos archivos definen e implementan la clase 
Configuracion, que maneja la carga y gestión de 
constantes desde un archivo de configuración. Sus funciones son:

Cargar Constantes: Lee las constantes definidas en 
un archivo y las almacena.

Obtener Constantes: Recupera el valor de una constante
 para su uso en cálculos.

Verificación de Existencia de Constantes: Comprueba si 
una constante está definida en el archivo de configuración.*/
#ifndef CONFIGURACION_H
#define CONFIGURACION_H

#include <unordered_map>
#include <string>

// Clase para manejar la configuración y constantes
class Configuracion {
public:
    // Constructor que carga las constantes desde un archivo
    Configuracion(const std::string& archivo);

    // Obtiene el valor de una constante
    double obtener(const std::string& constante) const;

    // Verifica si una constante está definida
    bool existe(const std::string& constante) const;

private:
    // Almacena las constantes
    std::unordered_map<std::string, double> constantes;

    // Carga las constantes desde un archivo
    void cargarArchivo(const std::string& archivo);
};

#endif // CONFIGURACION_H
