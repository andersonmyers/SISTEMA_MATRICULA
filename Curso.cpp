#include "Curso.h"

// Constructor predeterminado
Curso::Curso() : nombre(""), codigo(""), creditos(0), profesor("") {}

// Constructor con parámetros
Curso::Curso(std::string nombre, std::string codigo, int creditos, std::string profesor)
    : nombre(nombre), codigo(codigo), creditos(creditos), profesor(profesor) {}
