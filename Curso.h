#ifndef CURSO_H
#define CURSO_H

#include <string>

class Curso {
public:
    std::string nombre;
    std::string codigo;
    int creditos;
    std::string profesor;

    // Constructor predeterminado
    Curso();
    // Constructor con parámetros
    Curso(std::string nombre, std::string codigo, int creditos, std::string profesor);
};

#endif
