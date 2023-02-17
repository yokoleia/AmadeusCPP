#include "Encyclopedia.h"
#include <string>
#include <iostream>

using namespace std;

void Encyclopedia::SetEdition(string Edition) {
    this->edition = Edition;
}
void Encyclopedia::SetNumPages(int NumPages) {
    this->numPages = NumPages;
}

// TODO: Declare accessor functions -
string Encyclopedia::GetEdition() const {
    return this->edition;
}
int Encyclopedia::GetNumPages() const {
    return this->numPages;
}

// TODO: Declare a PrintInfo() function that overrides
//       the PrintInfo() in Book class
void Encyclopedia::PrintInfo()
{
    cout << "Book Information: " << endl;
    cout << "   Book Title: " << title << endl;
    cout << "   Author: " << author << endl;
    cout << "   Publisher: " << publisher << endl;
    cout << "   Publication Date: " << publicationDate << endl;
    cout << "   Edition: " << this->edition << endl;
    cout << "   Number of Pages: " << this->numPages << endl;
}