#include <gtest/gtest.h>
#include "Memoria.h"

TEST(MemoriaTest, AsignarObtener) {
    Memoria memoria;
    memoria.asignar("x", 42.0);
    EXPECT_EQ(memoria.obtener("x"), 42.0);
}

TEST(MemoriaTest, VariableNoDefinida) {
    Memoria memoria;
    EXPECT_THROW(memoria.obtener("y"), std::invalid_argument);
}
