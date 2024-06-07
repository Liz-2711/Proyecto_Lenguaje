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
    //parser();

    
    return 0;
}