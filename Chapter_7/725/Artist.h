#ifndef ARTISTH
#define ARTISTH
#include <string>
using namespace std;


class Artist {
    private: 
        string name;
        int birthYear;
        int deathYear;

    public:
        Artist();

        Artist(string artistName, int birthYear, int deathYear);
        
        string GetName() const;

        int GetBirthYear() const;

        int GetDeathYear() const;

        void PrintInfo() const;
        /*
        void SetName();
        void SetBirthYear();
        void SetDeathYear();
        */
};

#endif