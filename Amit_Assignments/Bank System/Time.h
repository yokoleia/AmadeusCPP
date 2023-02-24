#ifndef TIME_H
#define TIME_H

#include <chrono>
using namespace std;

class Time
{

public:
    static int get_current_year()
    {
        auto now = chrono::system_clock::now();
        auto time = chrono::system_clock::to_time_t(now);
        tm *now_tm = localtime(&time);
        return now_tm->tm_year + 1900; // std::tm::tm_year is years since 1900
    }
};

#endif // TIME_H
