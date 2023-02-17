#ifndef ARTWORKH
#define ARTWORKH
#include "Artist.h"
#include <string> 
using namespace std;

class Artwork {
    private: 
        string title;
        int yearCreated;
        Artist artist;
    public: 
        Artwork();
        Artwork(string title, int yearCreated, Artist artist);
        string GetTitle() const;
        int GetYearCreated() const;
        void PrintInfo() const;
};

#endif