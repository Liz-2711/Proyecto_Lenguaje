#include <iostream>
#include <vector>
#include <stack>
#include "lexer.h"
#include "parser.h"
using namespace std;

int main() {
    string input = "";
    cout << "Expresion: ";
    cin >> input;

    lexer(input);
    vector<string> errors = parser();
    if (errors.empty()) {
        cout << "Gramatica correcta." << endl;
    } else {
        cout << "Hay errores." << endl;
    }
    
    return 0;
}