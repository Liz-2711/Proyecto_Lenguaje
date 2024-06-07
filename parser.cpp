#include "lexer.h"
#include "parser.h"

Token currentToken;
Token nextToken;

// Inicio: OpenParenthesis, Number, Variable, Constant
// OpenParenthesis -> Number, Variable, Contant
// Number, Variable, Constant -> Operator, ClosedParenthesis
// ClosedParenthesis -> Operator
// Operator -> OpenParenthesis, Number, Variable, Constant

vector<string> errors;

void expression() {
    if (currentToken.type == Number || currentToken.type == Variable || currentToken.type == Constant) {
        currentToken = getToken();
        if (currentToken.type == Operator) {
            currentToken = getToken();
            expression(); 
        } else if (currentToken.type == CloseParentesis) {
            return;
        } else if (currentToken.type == End) {
            return;
        } else {
            errors.push_back("Token invalido " + currentToken.value);
            cout << "Error de Sintaxis: Token inválido " << currentToken.value << endl;
        }
    } else if (currentToken.type == OpenParentesis) {
        currentToken = getToken();
        expression();
        if (currentToken.type == CloseParentesis) {
            currentToken = getToken();
            if (currentToken.type == Operator) {
                currentToken = getToken();
                expression(); 
            } else if (currentToken.type == End) {
                return;
            } else {
                errors.push_back("Token invalido " + currentToken.value);
                cout << "Error de Sintaxis: Token inválido " << currentToken.value << endl;
            }
        } else {
                        errors.push_back("Token invalido " + currentToken.value);

            cout << "Error de Sintaxis: Se esperaba un ')' " << currentToken.value << endl;
        }
    } else {
                    errors.push_back("Token invalido " + currentToken.value);

        cout << "Error de Sintaxis: Token inválido " << currentToken.value << endl;
    }
}

void expression_list() {
    if (tokens.empty()) {
                    errors.push_back("Token invalido " + currentToken.value);

        cout << "Error de Sintaxis: No hay tokens para analizar" << endl;
        return;
    }

    currentToken = getToken();
    expression();

    if (currentToken.type != End) {
                    errors.push_back("Token invalido " + currentToken.value);

        cout << "Error de Sintaxis: Token inesperado al final de la expresión " << currentToken.value << endl;
    }
}

vector<string> parser() {
    try {
        expression_list();
        return errors;
    } catch (const std::exception &e) {
        errors.push_back("Error durante el analisis.");
        return errors;
    }
}
