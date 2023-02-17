#ifndef COURSEH
#define COURSEH

#include <iostream>
#include <string>

using namespace std;

class Course
{
    // TODO: Declare private data members
    protected: 
        string courseNumber;
        string title;

    public: 
    
    // TODO: Declare mutator functions
    void SetCourseNumber(string CourseNumber);
    void SetCourseTitle(string CourseTitle);


    // TODO: Declare accessor functions -
    string GetCourseNumber() const;
    string GetCourseTitle() const;

    // TODO: Declare PrintInfo()
    void PrintInfo() const;
};

#endif
