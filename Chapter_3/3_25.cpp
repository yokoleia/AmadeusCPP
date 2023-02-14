#include <iostream>
using namespace std;

int main() {
    int year;
    bool leapYear = false;

    cin >> year;
    if (year % 4 == 0) {
        leapYear = true;
        if (year % 100 == 0) {
            if (year % 400 != 0) {
                leapYear = false;
            }
        }
    }



    cout << year << " - ";
    if (leapYear) {
        cout << "leap year" << endl;
    } else {
        cout << "not a leap year" << endl;
    }

}