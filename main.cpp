// #include <iostream>
// #include <vector>
// #include <stack>
// #include "lexer.h"
// #include "parser.h"
// using namespace std;

// int main() {
//     string input = "";
//     cout << "Expresion: ";
//     cin >> input;

//     lexer(input);
//     vector<string> errors = parser();
//     if (errors.empty()) {
//         cout << "Gramatica correcta." << endl;
//     } else {
//         cout << "Hay errores." << endl;
//     }
    
//     return 0;
// }

#include <iostream>
#include "Evaluador.h"
#include "Memoria.h"
#include "Configuracion.h"
#include "Historial.h"

int main() {
    Memoria memoria;
    Configuracion configuracion("constantes.txt");  // Pasa el nombre del archivo de configuración
    Evaluador evaluador;
    Historial historial;
    
    std::string expresion;
    
    while (true) {
        std::cout << "Ingrese una expresión: ";
        std::getline(std::cin, expresion);
        
        if (expresion == "salir") {
            break;
        }
        
        std::string resultado = evaluador.evaluar(expresion, memoria, configuracion);
        
        if (resultado == "Expresión inválida") {
            std::cout << "Error de sintaxis encontrados:" << std::endl;
            std::cout << historial.obtenerHistorial() << std::endl;
        } else {
            historial.agregar(expresion, resultado);
            std::cout << "Resultado: " << resultado << std::endl;
            std::cout << "Historial: " << historial.obtenerHistorial() << std::endl;
        }
    }
    
    return 0;
}



// #include <iostream>
// #include "Evaluador.h"
// #include "Historial.h"
// #include "Memoria.h"
// #include "Configuracion.h"
// /*Este archivo es el punto de entrada del programa.
//  Aquí se maneja la interacción con el usuario, se 
//  inicializan los componentes necesarios (Evaluador, 
//  Historial, Memoria, Configuracion).*/
// int main() {
//     Evaluador evaluador;
//     Historial historial;
//     Memoria memoria;
//     Configuracion configuracion("config/constantes.txt");

//     std::string expresion;
//     while (true) {
//         std::cout << "Ingrese una expresión: ";
//         std::getline(std::cin, expresion);

//         if (expresion == "salir") break;

//         try {
//             std::string resultado = evaluador.evaluar(expresion, memoria, configuracion);
//             historial.agregar(expresion, resultado);
//             std::cout << "Resultado: " << resultado << std::endl;
//         } catch (const std::invalid_argument& e) {
//             std::cout << "Error: " << e.what() << std::endl;
//         }

//         std::cout << "Historial: " << std::endl;
//         historial.mostrar();
//     }

//     return 0;
