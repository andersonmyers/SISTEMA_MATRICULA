#include "Registration.h"
#include <iostream>

Registration::Registration() : student(nullptr), numCourses(0), cost(0.0) {}

Registration::Registration(Student* student)
    : student(student), numCourses(0), cost(0.0) {}

void Registration::registerCourse(Course* course) {
    if (numCourses < 10) {
        courses[numCourses++] = course;
        cost += course->credits * 12272.00;  
    }
}

void Registration::showRegistration() {
    std::cout << "Estudiante: " << student->name << std::endl;
    std::cout << "Cursos Matriculados: " << std::endl;
    for (int i = 0; i < numCourses; ++i) {
        std::cout << "- " << courses[i]->name << " (" << courses[i]->code << ")" << std::endl;
    }
    std::cout << "El costo total de los creditos es: " << cost <<" Colones"<< std::endl;
}
