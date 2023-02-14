#include <iostream>
#include <string>
using namespace std;

int main() {
    string firstName, lastName, userName;
    int birthYear;
    cin >> firstName >> lastName >> birthYear;

    userName = (lastName.size() < 6) ? lastName : lastName.substr(0, 5);
    userName += firstName.at(0);
    userName += to_string(birthYear % 100);

    cout << "Your login name: " << userName << endl;
    return 0;
}