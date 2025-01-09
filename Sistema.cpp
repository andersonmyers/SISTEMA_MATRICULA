#include "Sistema.h"
#include <iostream>

// Constructor de Sistema
Sistema::Sistema() : numEstudiantes(0), numCursos(0), numHorarios(0), numMatriculas(0) {}

// Funci�n para mostrar el men�
void Sistema::mostrarMenu() {
    std::cout << "\n1. Archivo\n";
    std::cout << "   1.1 Acerca de\n";
    std::cout << "   1.2 Salir\n";
    std::cout << "2. Mantenimiento\n";
    std::cout << "   2.1 Estudiantes\n";
    std::cout << "   2.2 Cursos\n";
    std::cout << "   2.3 Horarios\n";
    std::cout << "3. Matricula\n";
    std::cout << "   3.1 Registro de Matricula\n";
    std::cout << "4. Consulta\n";
    std::cout << "   4.1 Estudiantes\n";
    std::cout << "   4.2 Cursos\n";
    std::cout << "Selecciona una opcion: ";
}

// Funci�n para mostrar informaci�n acerca del sistema
void Sistema::mostrarAcercaDe() {
    std::cout << "\nSistema desarrollado por el Ingeniero Anderson Chacon, "
        << "due�o de Futures Company.\n"
        << "Este sistema fue desarrollado para brindar un uso f�cil "
        << "al sistema de matr�cula de la Universidad Nacional.\n"
        << "El sistema creado es muy intuitivo y f�cil de usar.\n"
        << "Soporte t�cnico a 62929423 y chaconsamuel8@gmail.com\n";
}

// Funci�n para agregar estudiantes al sistema
void Sistema::agregarEstudiante() {
    std::string nombre, cedula, carrera, nivel;
    std::cout << "Nombre del estudiante: ";
    std::cin >> nombre;
    std::cout << "C�dula: ";
    std::cin >> cedula;
    std::cout << "Carrera: ";
    std::cin >> carrera;
    std::cout << "Nivel: ";
    std::cin >> nivel;

    estudiantes[numEstudiantes++] = Estudiante(nombre, cedula, carrera, nivel); // Usando el constructor con par�metros
    std::cout << "Estudiante registrado exitosamente." << std::endl;
}

// Funci�n para ejecutar el sistema
void Sistema::ejecutar() {
    int opcion;
    do {
        mostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            mostrarAcercaDe();
            break;
        case 2:
            std::cout << "Seleccione una opci�n:\n1. Estudiantes\n2. Cursos\n3. Horarios\n";
            break;
        case 3:
            std::cout << "Registrar matr�cula\n";
            break;
        case 4:
            std::cout << "Consultar estudiantes o cursos\n";
            break;
        case 0:
            std::cout << "Saliendo del sistema...\n";
            break;
        default:
            std::cout << "Opci�n inv�lida.\n";
        }
    } while (opcion != 0);
}
