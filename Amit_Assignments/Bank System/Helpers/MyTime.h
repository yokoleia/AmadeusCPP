#ifndef MYTIME_H
#define MYTIME_H
#include <chrono>
#include <sstream>
#include <iomanip>

using namespace std;

class MyTime
{

public:
    static int GetCurrentYear()
    {
        
        
        auto now = chrono::system_clock::now();
        auto time = chrono::system_clock::to_time_t(now);
        tm *now_tm = localtime(&time);
        return now_tm->tm_year + 1900; 
    
    }
#include <chrono>
#include <ctime>

    static string GetCurrentDateTime()
    {
        auto now = chrono::system_clock::now();
        time_t time = chrono::system_clock::to_time_t(now);
        tm *now_tm = localtime(&time);

        stringstream ss;
        ss << put_time(now_tm, "%Y-%m-%d %H:%M:%S");

        return ss.str();
    }
};


#endif // TIME_H
