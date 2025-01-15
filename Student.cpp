#include "Student.h"
#include "Course.h"  

Student::Student() : name(""), id(""), major(""), level("") {}

Student::Student(std::string name, std::string id, std::string major, std::string level)
    : name(name), id(id), major(major), level(level) {}

void Student::enrollInCourse(Course* course) {
    courses.push_back(course);  
}

bool Student::isEnrolled(Course* course) const {
    for (const auto& c : courses) {
        if (c == course) {  
            return true;
        }
    }
    return false;
}
