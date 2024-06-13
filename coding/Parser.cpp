#include "./headers/Lexer.h"
#include "./headers/Parser.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Token currentToken;
Token nextToken;

string error = "";

void expression();

void match(TokenType expectedType) {
    if (currentToken.type == expectedType) {
        currentToken = getToken();
    } else {
        error = "Error de Sintaxis: Token invalido: " + currentToken.value;
        cout << "Error de Sintaxis: Token invalido: " << currentToken.value << endl;
    }
}

void factor() {
    if (currentToken.type == Number || currentToken.type == Variable || currentToken.type == Constant) {
        match(currentToken.type);
    } else if (currentToken.type == OpenParentesis) {
        match(OpenParentesis);
        expression();
        if (currentToken.type == CloseParentesis) {
            match(CloseParentesis);
        } else {
            error = "Error de Sintaxis: Se esperaba un ')' " + currentToken.value;
            cout << "Error de Sintaxis: Se esperaba un ')' " << currentToken.value << endl;
        }
    } else {
        error = "Error de Sintaxis: Token invalido " + currentToken.value;
        cout << "Error de Sintaxis: Token invalido: " << currentToken.value << endl;
    }
}

void term() {
    factor();
    while (currentToken.type == Operator) {
        match(Operator);
        factor();
    }
}

void expression() {
    term();
    while (currentToken.type == Operator) {
        match(Operator);
        term();
    }
}

void expression_list() {
    if (tokens.empty()) {
        cout << "Error de Sintaxis: La expresion esta vacia." << endl;
        error = "Error de Sintaxis: La expresion esta vacia.";
        return;
    }

    currentToken = getToken();
    expression();

    if (currentToken.type != End) {
        error = "Error de Sintaxis: Token inesperado al final de la expresion: " + currentToken.value;
        cout << "Error de Sintaxis: Token inesperado al final de la expresion: " << currentToken.value << endl;
    }
}

string parser() {
    error.clear();
    try {
        expression_list();
        return error;
    } catch (const std::exception &e) {
        tokens.clear();
        error = "Error durante el analisis.";
        return error;
    }
}
