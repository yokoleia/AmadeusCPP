#include "OfferedCourse.h"

// TODO: Declare mutator functions -
void OfferedCourse::SetInstructorName(string instructorName) {
    this->instructorName = instructorName;
}
void OfferedCourse::SetLocation(string classLocation)
{
    this->classLocation = classLocation;
}
void OfferedCourse::SetClassTime(string classTime) {
    this->classTime = classTime;
}

// TODO: Declare accessor functions -
string OfferedCourse::GetInstructorName() const {
    return this->instructorName;
}
string OfferedCourse::GetLocation() const {
    return this->classLocation;
}
string OfferedCourse::GetClassTime() const {
    return classTime;
}