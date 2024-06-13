#include "./headers/lexer.h"
#include "./headers/parser.h"
#include "./headers/configuracion.h"

vector<Token> tokens;
vector<Token> tokensTemp; 

Token token(string value, TokenType type) {
    return { value, type };
}

long long SHIFT_CURR = 0;
string shift(vector<string>& src) {
	string current = src.front();
	src.erase(src.begin());
	return current;
}

bool isNumber(const std::string& str) {
    bool hasDecimalPoint = false;
    for (char c : str) {
        if (!std::isdigit(c) && c != '.') {
            return false;
        }
        if (c == '.') {
            if (hasDecimalPoint) {
                return false;
            }
            hasDecimalPoint = true;
        }
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
        tokensTemp.push_back(currentToken);
        tokens.erase(tokens.begin());
        return currentToken;
    } else {
        return token("", TokenType::End);
    }
}

Token getNextToken() {
    if (tokens.size() > 1) {
        return tokens[1];
    } else {
        return token("", TokenType::End);
    }
}

std::vector<std::string> parse_input(const std::string& expression) {
    std::vector<std::string> tokens;
    std::string currentToken;
    std::string operators = "+-*/%()^";
    bool inNumber = false;
    bool inDecimal = false;

    for (size_t i = 0; i < expression.size(); ++i) {
        char c = expression[i];
        
        if (std::isspace(c)) {
            continue;
        }

        if (std::isalpha(c)) {
            if (inNumber) {
                tokens.push_back(currentToken);
                currentToken.clear();
                inNumber = false;
                inDecimal = false;
            }
            currentToken += c;
        } else if (std::isdigit(c)) {
            currentToken += c;
            inNumber = true;
        } else if (c == '.') {
            if (inDecimal) {
                std::cerr << "Error: Numero invalido: " << currentToken + c << std::endl;
                tokens.clear();
                return tokens;
            }
            if (!inNumber) {
                currentToken += '0';
            }
            currentToken += c;
            inNumber = true;
            inDecimal = true;
        } else if (operators.find(c) != std::string::npos) {
            if (!currentToken.empty()) {
                tokens.push_back(currentToken);
                currentToken.clear();
                inNumber = false;
                inDecimal = false;
            }
            tokens.push_back(std::string(1, c));
        } else {
            std::cerr << "Caracter Inesperado: " << c << std::endl;
            tokens.clear();
            return tokens;
        }
    }

    if (!currentToken.empty()) {
        tokens.push_back(currentToken);
    }

    return tokens;
}

string tokenize(string expression, Configuracion configuracion) {
    vector<string> src = parse_input(expression);
    for (std::string s : src) {
        cout << s << endl;
    }
    string error = "";
    while (!src.empty()) {
        //cout << src.front() << endl;
        if (src.front() == "+" || src.front() == "-" || src.front() == "*" || src.front() == "/" || src.front() == "%" || src.front() == "^") {
            tokens.push_back(token(shift(src), TokenType::Operator));
        } 
        else if (src.front() == "(") {
            tokens.push_back(token(shift(src), TokenType::OpenParentesis));
        }
        else if (src.front() == ")") {
            tokens.push_back(token(shift(src), TokenType::CloseParentesis));
        }
        else {
            if (isNumber(src.front())) {
                string number;
				while (!src.empty() && isNumber(src.front()))
				{
					number += shift(src);
				}
                cout << "Es" << number << endl;
				tokens.push_back(token(number, TokenType::Number));
            } else if (isAlpha(src.front())) {
                string ident = shift(src);
                cout << "Ident: " << ident << endl;
                double response = configuracion.obtener(ident);
                if (response) {
                    tokens.push_back(token(to_string(response), TokenType::Constant));
                } else {
                    return "La constante no existe.";
                }
                cout << response << endl;
            }
        }
    }
    return error;
}

string lexer(string expression, Configuracion configuracion) {
    string error = "";
    tokensTemp.clear();
    error = tokenize(expression, configuracion);
    if (error.empty()) {
        error = parser();
    }
    return error;
}