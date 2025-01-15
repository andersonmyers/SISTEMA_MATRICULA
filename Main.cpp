#include <iostream>
#include "System.h"

int main() {
    System system;
    int option;

    while (true) {
        system.showMenu();
        std::cin >> option;

        switch (option) {
        case 1:
            system.showFileSubMenu();
            int subOption;
            std::cin >> subOption;
            if (subOption == 1) {
                system.showAbout();
            }
            else if (subOption == 2) {
                std::cout << "Saliendo...\n";
                return 0;
            }
            break;
        case 2:
            std::cout << "\n1. Agregar Estudiante\n";
            std::cout << "2. Agregar Curso\n";
            std::cout << "3. Agregar Horario\n";
            std::cout << "Selecciona una opcion: ";
            int maintenanceOption;
            std::cin >> maintenanceOption;
            switch (maintenanceOption) {
            case 1:
                system.addStudent();
                break;
            case 2:
                system.addCourse();
                break;
            case 3:
                system.addSchedule();
                break;
            default:
                std::cout << "Opcion invalida.\n";
            }
            break;
        case 3:
            system.registerRegistration();
            break;
        case 4:
            std::cout << "\n1. Consultar Estudiantes\n";
            std::cout << "2. Consultar Cursos\n";
            std::cout << "3. Consultar Horarios\n";
            std::cout << "Selecciona una opcion: ";
            int queryOption;
            std::cin >> queryOption;
            switch (queryOption) {
            case 1:
                system.queryStudents();
                break;
            case 2:
                system.queryCourses();
                break;
            case 3:
                system.querySchedules();
                break;
            default:
                std::cout << "Opcion invalida.\n";
            }
            break;
        default:
            std::cout << "Opcion invalida. Intenta nuevamente.\n";
        }
    }

    return 0;
}
