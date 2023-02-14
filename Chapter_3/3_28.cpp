#include <iostream>
#include <iomanip>
using namespace std; 

int main() {
    const double HOMEWORK_MAX = 800.0;
    const double QUIZZES_MAX = 400.0;
    const double MIDTERM_MAX = 150.0;
    const double FINAL_MAX = 200.0;

    string status;
    double homeworkPoints, quizPoints, midtermPoints, finalPoints;
    cin >> status >> homeworkPoints >> quizPoints >> midtermPoints >> finalPoints;

    // NORMALISING GRADES AROUND 100%
    homeworkPoints  = (homeworkPoints   > HOMEWORK_MAX) ? HOMEWORK_MAX  : homeworkPoints;
    quizPoints      = (quizPoints       > QUIZZES_MAX)  ? QUIZZES_MAX   : quizPoints;
    midtermPoints   = (midtermPoints    > MIDTERM_MAX)  ? MIDTERM_MAX   : midtermPoints;
    finalPoints     = (finalPoints      > FINAL_MAX)    ? FINAL_MAX     : finalPoints;

    // NORMALISING AS PERCENTAGE
    homeworkPoints = homeworkPoints / HOMEWORK_MAX * 100;
    quizPoints     = quizPoints     / QUIZZES_MAX * 100;
    midtermPoints  = midtermPoints  / MIDTERM_MAX * 100;
    finalPoints    = finalPoints    / FINAL_MAX * 100;

    if (!((status == "UG") ||  (status == "G") || (status == "DL"))) {
        cout << "Error: student status must be UG, G or DL" << endl;
        return 0;
    } 

    cout << fixed << setprecision(1);
    cout << "Homework: "   << homeworkPoints << "%" << endl;
    cout << "Quizzes: "    << quizPoints     << "%" << endl;
    cout << "Midterm: "    << midtermPoints  << "%" << endl;
    cout << "Final Exam: " << finalPoints    << "%" << endl;

    double hwMultiplier;
    double qMultiplier;
    double mMultiplier;
    double fMultiplier;

    if (status == "G") {
        hwMultiplier = 0.15;
        qMultiplier  = 0.05;
        mMultiplier  = 0.35;
        fMultiplier  = 0.45;
    } else if (status == "UG") {

        hwMultiplier = 0.2;
        qMultiplier = 0.2;
        mMultiplier = 0.3;
        fMultiplier = 0.3;
    } else {

        hwMultiplier = 0.05;
        qMultiplier = 0.05;
        mMultiplier = 0.4;
        fMultiplier = 0.5;
    }

    double homeworkPercentage   = homeworkPoints * hwMultiplier;
    double quizPercentage       = quizPoints     * qMultiplier;
    double midtermPercentage    = midtermPoints  * mMultiplier;
    double finalPercentage      = finalPoints    * fMultiplier;
    double courseAverage        = (homeworkPercentage + quizPercentage + midtermPercentage + finalPercentage);
    
    cout << status << " average: " << courseAverage<< "%" << endl;

    
    char courseGrade;
    switch((int)(courseAverage/10)) {
        case 9:
            courseGrade = 'A';
            break;
        case 8:
            courseGrade = 'B';
            break;
        case 7:
            courseGrade = 'C';
            break;
        case 6:
            courseGrade = 'D';
            break;
        default:
            courseGrade = 'F';
            break;
    }
    cout << "Course grade: " << courseGrade << endl;



    return 0;
}