#include <gtest/gtest.h>
#include "Historial.h"

TEST(HistorialTest, AgregarYMostrar) {
    Historial historial;
    historial.agregar("3 + 5", "8");
    std::string expected = "3 + 5 = 8\n";
    EXPECT_EQ(historial.obtenerHistorial(), expected);
}
