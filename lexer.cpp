#include "lexer.h"
#include "parser.h"

vector<Token> tokens;

Token token(string value, TokenType type) {
    return { value, type };
}

long long SHIFT_CURR = 0;
string shift(vector<string>& src) {
	string current = src.front();
	src.erase(src.begin());
	return current;
}

bool isNumber(const string& str) {
	for (char c : str) {
		if (!isdigit(c))
			return false;
	}
	return true;
}

bool isAlpha(const std::string& str)
{
	for (char ch : str)
	{
		if (!isalpha(ch))
			return false;
	}
	return true;
}

Token getToken() {
    if (!tokens.empty()) {
        Token currentToken = tokens.front();
        tokens.erase(tokens.begin());
        return currentToken;
    } else {
        throw std::out_of_range("Tokens esta vacio.");
    }
}

Token getNextToken() {
    if (tokens.size() > 1) {
        return tokens[1];
    } else {
        throw std::out_of_range("Tokens esta vacio.");
    }
}

vector<string> parse_input(string expression) {
    vector<string> tokens;
    string exp;
    string currentToken;
    string operators = "+-*/%()";
    for (size_t i = 0; i < expression.size(); ++i) {
        char c = expression[i];
        
        if (std::isspace(c)) {
            continue;
        }
        if (std::isalpha(c)) {
            currentToken += c;
        } else if (std::isdigit(c) || c == '.') {
            currentToken += c;
        } else if (operators.find(c) != std::string::npos) {
            if (!currentToken.empty()) {
                tokens.push_back(currentToken);
                currentToken.clear();
            }
            tokens.push_back(std::string(1, c));
        } else {
            std::cerr << "Caracter Inesperado: " << c << std::endl;
        }
    }

    if (!currentToken.empty()) {
        tokens.push_back(currentToken);
    }
    cout << "Finalizado" << endl;
    return tokens;
}

void tokenize(string expression) {
    vector<string> src = parse_input(expression);
    cout << "Tokeniza" << endl;

    while (!src.empty()) {
        //cout << src.front() << endl;
        if (src.front() == "+" || src.front() == "-" || src.front() == "*" || src.front() == "/" || src.front() == "%") {
            tokens.push_back(token(shift(src), TokenType::Operator));
        } 
        else if (src.front() == "(") {
            cout << "Is open par" << endl;
            tokens.push_back(token(shift(src), TokenType::OpenParentesis));
        }
        else if (src.front() == ")") {
            cout << "Is closed par" << endl;
            tokens.push_back(token(shift(src), TokenType::CloseParentesis));
        }
        else {
            if (isNumber(src.front())) {
                string number;
				while (!src.empty() && isNumber(src.front()))
				{
					number += shift(src);
				}

				tokens.push_back(token(number, TokenType::Number));
            } else if (isAlpha(src.front())) {
                string ident = shift(src);
                tokens.push_back(token(ident, TokenType::Variable));
            }
        }
    }
}

void lexer(string expression) {
    tokenize(expression);
    parser();
}
