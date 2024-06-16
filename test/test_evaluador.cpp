#include <gtest/gtest.h>
#include "Evaluador.h"
#include "Memoria.h"
#include "Configuracion.h"

TEST(EvaluadorTest, EvaluarExpresionValida) {
    Memoria memoria;
    Configuracion configuracion("config.txt");
    Evaluador evaluador;
    std::string resultado = evaluador.evaluar("3 + 5", memoria, configuracion);
    EXPECT_EQ(resultado, "8");
}

TEST(EvaluadorTest, EvaluarExpresionInvalida) {
    Memoria memoria;
    Configuracion configuracion("config.txt");
    Evaluador evaluador;
    std::string resultado = evaluador.evaluar("3 +", memoria, configuracion);
    EXPECT_EQ(resultado, "Expresión inválida");
}
