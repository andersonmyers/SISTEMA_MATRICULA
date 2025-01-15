#ifndef CURSO_H
#define CURSO_H

#include <string>
#include "Schedule.h"

class Course {
public:
    std::string name;
    std::string code;
    int credits;
    std::string professor;
    Schedule schedule;

    Course();
    Course(std::string name, std::string code, int credits, std::string professor);

    void assignSchedule(std::string day, std::string start_time, std::string end_time, std::string room);
    bool checkConflict(Course* anotherCourse);
};

#endif
