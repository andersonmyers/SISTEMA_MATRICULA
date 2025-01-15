#include "System.h"
#include <iostream>

System::System() {
    numStudents = 0;
    numCourses = 0;
    numSchedules = 0;
    numRegistrations = 0;

    courses[numCourses++] = Course("Matematicas", "MAT101", 4, "Elizabeth");
    courses[numCourses++] = Course("Fisica", "PHY102", 3, "Juan Gamboa");
    courses[numCourses++] = Course("Programacion", "PRO103", 3, "Gabriel Juan");

    courses[0].assignSchedule("Lunes", "08:00", "10:00", " 11");
    courses[1].assignSchedule("Martes", "10:00", "12:00", " 12");
    courses[2].assignSchedule("Miércoles", "14:00", "16:00", " 10");

}

void System::showMenu() {
    std::cout << "#===  SISTEMA DE MATRICULA  ===#\n";
    std::cout << "1. Archivo\n"; 
    std::cout << "2. Mantenimiento\n"; 
    std::cout << "3. Matricular\n"; 
    std::cout << "4. Consultar\n"; 
    std::cout << "Selecciona una opcion: "; 
}

void System::showFileSubMenu() {
    std::cout << "1. Acerca de\n"; 
    std::cout << "2. Salir\n"; 
}

void System::showAbout() {
    std::cout << "sistema desarrollado por Anderson y la empresa BloxCompays, sistema implementado para la universidad y emjorar el sistema de matricula\n"; 
}

void System::addStudent() {
    if (numStudents < 10) {
        std::string name, id, major, level;
        std::cout << "Introduce el nombre del estudiante: "; 
        std::cin >> name;
        std::cout << "Introduce el ID: "; 
        std::cin >> id;
        std::cout << "Introduce la carrera: "; 
        std::cin >> major;
        std::cout << "Introduce el nivel: ";
        std::cin >> level;

        students[numStudents] = Student(name, id, major, level);
        numStudents++;
    }
    else {
        std::cout << "No hay espacio para a estudiantes.\n";
    }
}

void System::addCourse() {
    if (numCourses < 10) {
        std::string name, code, professor, day, start_time, end_time, room;
        int credits;

        std::cout << "Introduce el nombre del curso: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Introduce el codigo: ";
        std::cin >> code;
        std::cout << "Introduce los creditos: ";
        std::cin >> credits;
        std::cout << "Introduce el profesor: ";
        std::cin.ignore();
        std::getline(std::cin, professor);

        Course newCourse(name, code, credits, professor);

        std::cout << "Introduce el dia del horario: ";
        std::getline(std::cin, day);
        std::cout << "Introduce la hora de inicio: ";
        std::cin >> start_time;
        std::cout << "Introduce la hora de fin: ";
        std::cin >> end_time;
        std::cout << "Introduce el aula: ";
        std::cin >> room;

        newCourse.assignSchedule(day, start_time, end_time, room);

        bool conflict = false;
        for (int i = 0; i < numCourses; ++i) {
            if (courses[i].checkConflict(&newCourse)) {
                conflict = true;
                break;
            }
        }

        if (conflict) {
            std::cout << "¡Error! El curso tiene un conflicto de horario con otro curso.\n";
        }
        else {
            courses[numCourses++] = newCourse;
            std::cout << "Curso agregado exitosamente.\n";
        }
    }
    else {
        std::cout << "No se pueden agregar más cursos.\n";
    }
}
void System::addSchedule() {
    if (numSchedules < 10) {
        std::string day, start_time, end_time, room;
        std::cout << "Introduce el dia del horario: ";
        std::cin >> day;
        std::cout << "Introduce la hora de inicio: ";
        std::cin >> start_time;
        std::cout << "Introduce la hora de fin: ";
        std::cin >> end_time;
        std::cout << "Introduce el aula: ";
        std::cin >> room;

        // Crear un nuevo horario y agregarlo sin verificar conflictos
        Schedule newSchedule(day, start_time, end_time, room);
        schedules[numSchedules++] = newSchedule;
        std::cout << "Horario agregado exitosamente.\n";
    }
    else {
        std::cout << "No se pueden agregar más horarios.\n";
    }
}

void System::registerRegistration() {
    if (numStudents == 0) {
        std::cout << "No hay estudiantes matriculados.\n";
        return;
    }

    std::cout << "Selecciona el estudiante a matricular: \n";
    for (int i = 0; i < numStudents; ++i) {
        
        std::cout << i + 1 << ". " << students[i].name << " (ID: " << students[i].id << ", Carrera: "
            << students[i].major << ", Nivel: " << students[i].level << ")\n";
    }

    int selection;
    std::cin >> selection;

    Student* selectedStudent = &students[selection - 1];

    
    std::cout << "Estudiante seleccionado: " << selectedStudent->name << "\n";
    std::cout << "ID: " << selectedStudent->id << "\n";
    std::cout << "Carrera: " << selectedStudent->major << "\n";
    std::cout << "Nivel: " << selectedStudent->level << "\n";

    Registration newRegistration(selectedStudent);

    std::cout << "Selecciona los cursos a matricular: \n";
    for (int i = 0; i < numCourses; ++i) {
        std::cout << i + 1 << ". " << courses[i].name << "\n";
    }

    int option = 0;
    while (true) {
        std::cout << "Introduce el numero del curso a matricular (0 para terminar): ";
        std::cin >> option;

        if (option == 0) break;

        if (option > 0 && option <= numCourses) {
            newRegistration.registerCourse(&courses[option - 1]);
        }
    }

    registrations[numRegistrations++] = newRegistration;
    std::cout << "Registro completado con exito.\n";

    newRegistration.showRegistration();
}

void System::queryCourses() {
    std::cout << "Numero de cursos registrados: " << numCourses << "\n";
    for (int i = 0; i < numCourses; ++i) {
        std::cout << courses[i].name << " (" << courses[i].code << ") - "
            << "Profesor: " << courses[i].professor << " | "
            << "Horario: " << courses[i].schedule.day << " de "
            << courses[i].schedule.start_time << " a "
            << courses[i].schedule.end_time << " | "
            << "Aula: " << courses[i].schedule.room << "\n";
    }
}

void System::querySchedules() {
    std::cout << "Horarios registrados: \n";
    for (int i = 0; i < numSchedules; ++i) {
        std::cout << "Horario " << i + 1 << " - "
            << schedules[i].day << " - "
            << schedules[i].start_time << " a "
            << schedules[i].end_time << " - "
            << "Aula: " << schedules[i].room << " - Libre\n";
    }
}

void System::queryStudents() {
    std::cout << "Estudiantes registrados: \n";
    for (int i = 0; i < numStudents; ++i) {
        std::cout << "Nombre: " << students[i].name << "\n";
        std::cout << "ID: " << students[i].id << "\n";
        std::cout << "Carrera: " << students[i].major << "\n";
        std::cout << "Nivel: " << students[i].level << "\n";
        std::cout << "Cursos matriculados:\n";

       
        bool hasCourses = false;
        for (int j = 0; j < numRegistrations; ++j) {
            if (registrations[j].student == &students[i]) {
                hasCourses = true;
                for (int k = 0; k < registrations[j].numCourses; ++k) {
                    std::cout << "- " << registrations[j].courses[k]->name << "\n";
                }
            }
        }

        if (!hasCourses) {
            std::cout << "No tiene cursos matriculados.\n";
        }
        std::cout << "--------------------------------------------\n";  // Separador
    }
}
