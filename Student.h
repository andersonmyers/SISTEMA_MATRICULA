#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>
#include <vector>
#include "Course.h"  // Asegúrate de incluir el encabezado de Course

class Student {
public:
    std::string name;
    std::string id;
    std::string major;
    std::string level;

    
    std::vector<Course*> courses;

    Student();
    Student(std::string name, std::string id, std::string major, std::string level);

   
    void enrollInCourse(Course* course);

    
    bool isEnrolled(Course* course) const;
};

#endif
