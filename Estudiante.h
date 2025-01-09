#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>

class Estudiante {
public:
    std::string nombre;
    std::string cedula;
    std::string carrera;
    std::string nivel;

    // Constructor predeterminado
    Estudiante();
    // Constructor con par�metros
    Estudiante(std::string nombre, std::string cedula, std::string carrera, std::string nivel);
};

#endif
