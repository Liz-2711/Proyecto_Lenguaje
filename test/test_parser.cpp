#include <gtest/gtest.h>
#include "parser.h"
#include "lexer.h"

TEST(ParserTest, ValidExpression) {
    std::vector<Token> tokens;
    tokenize("3 + 5", tokens);
    expression_list(tokens);
    EXPECT_TRUE(errors.empty());
}

TEST(ParserTest, InvalidExpression) {
    std::vector<Token> tokens;
    tokenize("3 +", tokens);
    expression_list(tokens);
    EXPECT_FALSE(errors.empty());
    EXPECT_EQ(errors[0], "Token invalido ");
}
