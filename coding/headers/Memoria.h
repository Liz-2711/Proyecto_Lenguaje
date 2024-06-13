
#ifndef MEMORIA_H
#define MEMORIA_H

#include <unordered_map>
#include <string>

class Memoria {
public:
    void asignar(const std::string& variable, double valor);

    double obtener(const std::string& variable) const;

    bool existe(const std::string& variable) const;

private:
    std::unordered_map<std::string, double> variables; 
};

#endif 
