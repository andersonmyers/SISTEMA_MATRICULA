#include "Sistema.h"
#include <iostream>

// Constructor de Sistema
Sistema::Sistema() : numEstudiantes(0), numCursos(0), numHorarios(0), numMatriculas(0) {}

// Función para mostrar el menú
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

// Función para mostrar información acerca del sistema
void Sistema::mostrarAcercaDe() {
    std::cout << "\nSistema desarrollado por el Ingeniero Anderson Chacon, "
        << "dueño de Futures Company.\n"
        << "Este sistema fue desarrollado para brindar un uso fácil "
        << "al sistema de matrícula de la Universidad Nacional.\n"
        << "El sistema creado es muy intuitivo y fácil de usar.\n"
        << "Soporte técnico a 62929423 y chaconsamuel8@gmail.com\n";
}

// Función para agregar estudiantes al sistema
void Sistema::agregarEstudiante() {
    std::string nombre, cedula, carrera, nivel;
    std::cout << "Nombre del estudiante: ";
    std::cin >> nombre;
    std::cout << "Cédula: ";
    std::cin >> cedula;
    std::cout << "Carrera: ";
    std::cin >> carrera;
    std::cout << "Nivel: ";
    std::cin >> nivel;

    estudiantes[numEstudiantes++] = Estudiante(nombre, cedula, carrera, nivel); // Usando el constructor con parámetros
    std::cout << "Estudiante registrado exitosamente." << std::endl;
}

// Función para ejecutar el sistema
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
            std::cout << "Seleccione una opción:\n1. Estudiantes\n2. Cursos\n3. Horarios\n";
            break;
        case 3:
            std::cout << "Registrar matrícula\n";
            break;
        case 4:
            std::cout << "Consultar estudiantes o cursos\n";
            break;
        case 0:
            std::cout << "Saliendo del sistema...\n";
            break;
        default:
            std::cout << "Opción inválida.\n";
        }
    } while (opcion != 0);
}
