#include "Course.h"

Course::Course() : name(""), code(""), credits(0), professor("") {}

Course::Course(std::string name, std::string code, int credits, std::string professor)
    : name(name), code(code), credits(credits), professor(professor) {}

void Course::assignSchedule(std::string day, std::string start_time, std::string end_time, std::string room) {
    schedule = Schedule(day, start_time, end_time, room);
}

bool Course::checkConflict(Course* otherCourse) {
    
    if (this->schedule.day == otherCourse->schedule.day) {
        
        if ((this->schedule.start_time < otherCourse->schedule.end_time) &&
            (this->schedule.end_time > otherCourse->schedule.start_time)) {
            return true; 
        }
    }
    return false;  
}
