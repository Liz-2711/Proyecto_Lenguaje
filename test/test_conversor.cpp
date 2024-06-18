#include <gtest/gtest.h>
#include "Conversor.h"

TEST(ConversorTest, InfijaAPostfija) {
    std::string infija = "3+5";
    std::string postfija = infijaAPostfija(infija);
    EXPECT_EQ(postfija, "35+");
}
