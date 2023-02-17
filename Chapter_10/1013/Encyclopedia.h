#ifndef ENCYCLOPEDIA_H
#define ENCYCLOPEDIA_H
#include "Book.h"
#include <string>
using namespace std;

class Encyclopedia : public Book  {
    private:
        string edition;
        int numPages;


    public:
    // TODO: Declare mutator functions -
    void SetEdition(string Edition);
    void SetNumPages(int NumPages);

    // TODO: Declare accessor functions -
    string GetEdition() const; 
    int GetNumPages() const;

    // TODO: Declare a PrintInfo() function that overrides
    //       the PrintInfo() in Book class
    void PrintInfo();
};
#endif