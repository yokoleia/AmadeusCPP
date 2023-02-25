#ifndef MYTIME_H
#define MYTIME_H

using namespace std;

#include <chrono>
class MyTime
{

public:
    static int get_current_year()
    {
        return 2023;
        
        auto now = chrono::system_clock::now();
        auto time = chrono::system_clock::to_time_t(now);
        tm *now_tm = localtime(&time);
        return now_tm->tm_year + 1900; // std::tm::tm_year is years since 1900
    
    }
};


#endif // TIME_H
