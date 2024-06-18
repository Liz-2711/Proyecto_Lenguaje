#include <gtest/gtest.h>
#include "Evaluador.h"
#include "Memoria.h"
#include "Configuracion.h"
#include <string>

// Helper function to evaluate an expression
std::string evaluarExpresion(const std::string& expresion) {
    Memoria memoria;
    Configuracion configuracion("constantes.txt");  // Asegúrate de que este archivo existe
    Evaluador evaluador;
    return evaluador.evaluar(expresion, memoria, configuracion);
}

// Tests for valid expressions
TEST(MainTest, ValidIntegerExpression) {
    EXPECT_EQ(evaluarExpresion("3 + 5"), "8");
}

TEST(MainTest, ValidFloatExpression) {
    EXPECT_EQ(evaluarExpresion("3.5 + 2.1"), "5.6");
}

TEST(MainTest, ValidExpressionWithParentheses) {
    EXPECT_EQ(evaluarExpresion("(3 + 5) * 2"), "16");
}

TEST(MainTest, ValidExpressionWithPriority) {
    EXPECT_EQ(evaluarExpresion("3 + 5 * 2"), "13");
}

TEST(MainTest, ValidPostfixEvaluation) {
    EXPECT_EQ(evaluarExpresion("3 5 +"), "8");
}

TEST(MainTest, ValidExponentiation) {
    EXPECT_EQ(evaluarExpresion("2 ^ 3"), "8");
}

// Tests for invalid expressions
TEST(MainTest, InvalidExpressionWithIncompleteParentheses) {
    EXPECT_EQ(evaluarExpresion("(3 + 5 * 2"), "Expresión inválida");
}

TEST(MainTest, InvalidExpressionWithInvalidCharacters) {
    EXPECT_EQ(evaluarExpresion("3 + 5a"), "Expresión inválida");
}

TEST(MainTest, InvalidPostfixEvaluation) {
    EXPECT_EQ(evaluarExpresion("3 5 + *"), "Expresión inválida");
}

TEST(MainTest, DivisionByZero) {
    EXPECT_EQ(evaluarExpresion("5 / 0"), "Error: División por cero");
}

TEST(MainTest, ModulusByZero) {
    EXPECT_EQ(evaluarExpresion("5 % 0"), "Error: División por cero");
}

// Additional tests for edge cases and complex expressions
TEST(MainTest, ValidComplexExpression) {
    EXPECT_EQ(evaluarExpresion("(3 + 5) * 2 - 8 / 4 + 3^2"), "24");
}

TEST(MainTest, ValidNestedParentheses) {
    EXPECT_EQ(evaluarExpresion("((2 + 3) * 2) ^ 2"), "100");
}

TEST(MainTest, ValidExpressionWithConstants) {
    EXPECT_EQ(evaluarExpresion("PI * 2"), "6.28318");  // Assuming PI is defined as 3.14159 in constantes.txt
}

TEST(MainTest, ValidExpressionWithVariables) {
    Memoria memoria;
    memoria.asignar("x", 5);
    Evaluador evaluador;
    Configuracion configuracion("constantes.txt");
    EXPECT_EQ(evaluador.evaluar("x * 2", memoria, configuracion), "10");
}

TEST(MainTest, InvalidExpressionWithMultipleOperators) {
    EXPECT_EQ(evaluarExpresion("3 + * 5"), "Expresión inválida");
}
