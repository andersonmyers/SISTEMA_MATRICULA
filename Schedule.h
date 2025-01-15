#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>

class Schedule {
public:
    std::string day;
    std::string start_time;
    std::string end_time;
    std::string room;

    Schedule();
    Schedule(std::string day, std::string start_time, std::string end_time, std::string room);
};

#endif
