#ifndef MATRICULA_H
#define MATRICULA_H

#include "Estudiante.h"
#include "Curso.h"

class Matricula {
public:
    Estudiante* estudiante;
    Curso* cursos[10];  // Limite de 10 cursos
    int numCursos;
    double costo;

    // Constructor predeterminado
    Matricula();
    // Constructor con parámetros
    Matricula(Estudiante* estudiante);

    void registrarCurso(Curso* curso);
    void mostrarMatricula();
};

#endif
