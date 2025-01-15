#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "Student.h"
#include "Course.h"

class Registration {
public:
    Student* student;
    Course* courses[10];
    int numCourses;
    double cost;

    Registration();
    Registration(Student* student);

    void registerCourse(Course* course);
    void showRegistration();
};

#endif
