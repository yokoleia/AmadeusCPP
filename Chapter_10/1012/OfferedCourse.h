#ifndef OFFERED_COURSEH
#define OFFERED_COURSEH

#include "Course.h"

class OfferedCourse : public Course
{
    // TODO: Declare private data members
    private: 
        string instructorName;
        string classLocation; 
        string classTime; 
    public: 

        // TODO: Declare mutator functions -
        void SetInstructorName(string instructorName);
        void SetLocation(string classLocation);
        void SetClassTime(string classTime);

        // TODO: Declare accessor functions -
        string GetInstructorName() const;
        string GetLocation() const;
        string GetClassTime() const;
};

#endif