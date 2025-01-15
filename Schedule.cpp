#include "Schedule.h"

Schedule::Schedule() : day(""), start_time(""), end_time(""), room("") {}

Schedule::Schedule(std::string day, std::string start_time, std::string end_time, std::string room)
    : day(day), start_time(start_time), end_time(end_time), room(room) {}
