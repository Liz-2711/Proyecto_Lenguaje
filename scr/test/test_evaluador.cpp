#include "gtest/gtest.h"
#include "Evaluador.h"
#include "Memoria.h"
#include "Configuracion.h"

TEST(EvaluadorTest, ExpresionValida) {
    Memoria memoria;
    Configuracion configuracion;
    Evaluador evaluador;

    std::string expresion = "3 + 5";
    std::string resultado = evaluador.evaluar(expresion, memoria, configuracion);

    EXPECT_EQ(resultado, "8");
}

TEST(EvaluadorTest, ExpresionInvalida) {
    Memoria memoria;
    Configuracion configuracion;
    Evaluador evaluador;

    std::string expresion = "3 + ";
    std::string resultado = evaluador.evaluar(expresion, memoria, configuracion);

    EXPECT_EQ(resultado, "Expresión inválida");
}

// Agrega más pruebas según sea necesario

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
