#include <map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    string studentName;
    double studentGrade;

    map<string, double> studentGrades;

    // Students' grades (pre-entered)
    studentGrades.emplace("Harry Rawlins", 84.3);
    studentGrades.emplace("Stephanie Kong", 91.0);
    studentGrades.emplace("Shailen Tennyson", 78.6);
    studentGrades.emplace("Quincy Wraight", 65.4);
    studentGrades.emplace("Janine Antinori", 98.2);

    // TODO: Read in new grade for a student, output initial
    //       grade, replace with new grade in map,
    //       output new grade
    // Quincy Wraight's original grade: 65.4
    // Quincy Wraight's new grade: 73.1
    getline(cin,studentName);
    cin >> studentGrade;
    
    if (studentGrades.count(studentName))
    {
        cout << studentName << "'s original grade: ";
        cout << studentGrades.at(studentName) << endl;

        studentGrades.erase(studentName);
        studentGrades.emplace(studentName, studentGrade);

        cout << studentName << "'s new grade: ";
        cout << studentGrades.at(studentName) << endl;
    }

    return 0;
}