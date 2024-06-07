#include "lexer.h"
#include "parser.h"

Token currentToken;
Token nextToken;

// Inicio: OpenParenthesis, Number, Variable, Constant
// OpenParenthesis -> Number, Variable, Contant
// Number, Variable, Constant -> Operator, ClosedParenthesis
// ClosedParenthesis -> Operator
// Operator -> OpenParenthesis, Number, Variable, Constant

void expression() {
    if (currentToken.type == Number) {
        currentToken = getToken();
        if (currentToken.type == Operator) {
            currentToken = getToken();
        } else {
            cout << "Error de Sintaxis: Token invalido " << currentToken.value << endl;
        }
    } 
    else if (currentToken.type == Variable) {

    }
    else if (currentToken.type == Constant) {

    }
    else {
        cout << "Error de Sintaxis: Token invalido " << currentToken.value << endl;
    }
}

void expression_list() {
    currentToken = getToken();
    if (currentToken.type == OpenParentesis) {
        currentToken = getToken();
    }
    else if (currentToken.type == Number) {

    } 
    else if (currentToken.type == Variable) {

    }
    else if (currentToken.type == Constant) {

    }
    else {
        cout << "Error de Sintaxis: Token invalido " << currentToken.value << endl;
    }
}

bool parser() {
    expression_list();
}