#include "Horario1.h"

// Constructor predeterminado
Horario1::Horario1() : dia(""), hora_inicio(""), hora_fin(""), aula("") {}

// Constructor con parámetros
Horario1::Horario1(std::string dia, std::string hora_inicio, std::string hora_fin, std::string aula)
    : dia(dia), hora_inicio(hora_inicio), hora_fin(hora_fin), aula(aula) {}
