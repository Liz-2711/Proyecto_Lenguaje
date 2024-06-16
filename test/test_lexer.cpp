#include <gtest/gtest.h>
#include "lexer.h"

TEST(LexerTest, TokenizeSimpleExpression) {
    std::vector<Token> tokens;
    tokenize("3 + 5", tokens);
    ASSERT_EQ(tokens.size(), 3);
    EXPECT_EQ(tokens[0].value, "3");
    EXPECT_EQ(tokens[1].value, "+");
    EXPECT_EQ(tokens[2].value, "5");
}

TEST(LexerTest, TokenizeWithParentheses) {
    std::vector<Token> tokens;
    tokenize("(3 + 5) * 2", tokens);
    ASSERT_EQ(tokens.size(), 7);
    EXPECT_EQ(tokens[0].value, "(");
    EXPECT_EQ(tokens[1].value, "3");
    EXPECT_EQ(tokens[2].value, "+");
    EXPECT_EQ(tokens[3].value, "5");
    EXPECT_EQ(tokens[4].value, ")");
    EXPECT_EQ(tokens[5].value, "*");
    EXPECT_EQ(tokens[6].value, "2");
}
