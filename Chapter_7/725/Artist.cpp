#include "Artist.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

Artist::Artist() {
    name = "unknown";
    birthYear = -1;
    deathYear = -1;
}

Artist::Artist(string artistName, int birthYear, int deathYear) {
    this->name = artistName;
    this->birthYear = birthYear;
    this->deathYear = deathYear;
}

string Artist::GetName() const {
    return name;
}

int Artist::GetBirthYear() const {
    return birthYear;
}

int Artist::GetDeathYear() const {
    return deathYear;
}

void Artist::PrintInfo() const {
    cout << "Artist: " << name << " ";
    if ((birthYear < 0) && (deathYear < 0)) {
        cout << "(unknown)";
    }
    else if (deathYear < 0) {
        cout << "(" << birthYear << " to present)";
    } else { 
        cout << "(" << birthYear << " to " << deathYear << ")";
    }
    cout << endl;
}