#ifndef HORARIO1_H
#define HORARIO1_H

#include <string>

class Horario1 {
public:
    std::string dia;
    std::string hora_inicio;
    std::string hora_fin;
    std::string aula;

    // Constructor predeterminado
    Horario1();
    // Constructor con parámetros
    Horario1(std::string dia, std::string hora_inicio, std::string hora_fin, std::string aula);
};

#endif
