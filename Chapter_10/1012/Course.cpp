#include "Course.h"
using namespace std;

// TODO: Define mutator functions -
void Course::SetCourseNumber(string CourseNumber) {
    this->courseNumber = CourseNumber;
}
void Course::SetCourseTitle(string CourseTitle) {
    this->title = CourseTitle;
}

// TODO: Define accessor functions -
string Course::GetCourseNumber() const {
    return this->courseNumber;
} 

string Course::GetCourseTitle() const {
    return this->title;
}

    // TODO: Define PrintInfo()
void Course::PrintInfo() const{
    cout << "Course Information:" << endl;
    cout << "   Course Number: " << this->courseNumber << endl;
    cout << "   Course Title: " << this->title << endl;
}