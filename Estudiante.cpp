#include "Estudiante.h"

// Constructor predeterminado
Estudiante::Estudiante() : nombre(""), cedula(""), carrera(""), nivel("") {}

// Constructor con parámetros
Estudiante::Estudiante(std::string nombre, std::string cedula, std::string carrera, std::string nivel)
    : nombre(nombre), cedula(cedula), carrera(carrera), nivel(nivel) {}
