#ifndef SISTEMA_H
#define SISTEMA_H

#include "Estudiante.h"
#include "Curso.h"
#include "Horario1.h"
#include "Matricula.h"

class Sistema {
private:
    Estudiante estudiantes[10];  // Limite de 10 estudiantes
    Curso cursos[10];            // Limite de 10 cursos
    Horario1 horarios[10];       // Limite de 10 horarios
    Matricula matriculas[10];    // Limite de 10 matriculas
    int numEstudiantes;
    int numCursos;
    int numHorarios;
    int numMatriculas;

public:
    Sistema();  // Declaración del constructor

    void mostrarMenu();
    void mostrarAcercaDe();
    void agregarEstudiante();
    void agregarCurso();
    void agregarHorario();
    void registrarMatricula();
    void consultarEstudiantes();
    void consultarCursos();
    void ejecutar();  // Función para ejecutar el sistema
};

#endif // SISTEMA_H
