#ifndef SYSTEM_H
#define SYSTEM_H

#include "Student.h"
#include "Course.h"
#include "Schedule.h"
#include "Registration.h"

class System {
private:
    Student students[10];
    Course courses[10];
    Schedule schedules[10];
    Registration registrations[10];
    int numStudents;
    int numCourses;
    int numSchedules;
    int numRegistrations;

public:
    System();

    void showMenu();
    void showFileSubMenu();
    void showAbout();
    void addStudent();
    void addCourse();
    void addSchedule();
    void registerRegistration();
    void queryStudents();
    void queryCourses();
    void querySchedules();
    void execute();
};

#endif
