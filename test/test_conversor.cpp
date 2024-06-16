#include <gtest/gtest.h>
#include "Conversor.h"

TEST(ConversorTest, InfijaAPostfija) {
    std::string expresion = "3 + 5 * ( 2 - 8 )";
    std::string resultado = infijaAPostfija(expresion);
    EXPECT_EQ(resultado, "3528-*+");
}
