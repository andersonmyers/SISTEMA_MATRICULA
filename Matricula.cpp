#include "Matricula.h"
#include <iostream>

// Constructor predeterminado
Matricula::Matricula() : estudiante(nullptr), numCursos(0), costo(0.0) {}

// Constructor con parámetros
Matricula::Matricula(Estudiante* estudiante)
    : estudiante(estudiante), numCursos(0), costo(0.0) {}

void Matricula::registrarCurso(Curso* curso) {
    if (numCursos < 10) {
        cursos[numCursos++] = curso;
        costo += curso->creditos * 50.0;  // Calcula el costo de la matrícula
    }
}

void Matricula::mostrarMatricula() {
    std::cout << "Estudiante: " << estudiante->nombre << std::endl;
    std::cout << "Cursos Matriculados: " << std::endl;
    for (int i = 0; i < numCursos; ++i) {
        std::cout << "- " << cursos[i]->nombre << " (" << cursos[i]->codigo << ")" << std::endl;
    }
    std::cout << "Costo total: " << costo << std::endl;
}
