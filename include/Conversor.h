// #ifndef CONVERSOR_H
// #define CONVERSOR_H


// #include <string>
// #include <vector>

// enum class TokenType {
//     Number,
//     Operator,
//     OpenParenthesis,
//     CloseParenthesis,
//     End
// };

// struct Token {
//     std::string value;
//     TokenType type;
// };

// class ConversorInfijoPostfijo {
// public:
//     static std::vector<Token> convertir(const std::string& expresion);

// private:
//     static std::vector<Token> tokenize(const std::string& expression);
//     static std::vector<Token> shuntingYard(const std::vector<Token>& tokens);
//     static bool esOperador(char c);
//     static int precedencia(char operador);
// };

// #endif // CONVERSOR


#ifndef CONVERSOR_H
#define CONVERSOR_H

#include <string>

std::string infijaAPostfija(const std::string& expresion);

#endif // CONVERSOR_H
