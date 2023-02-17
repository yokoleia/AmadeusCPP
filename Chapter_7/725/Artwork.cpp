#include "Artwork.h"
#include "Artist.h"
#include <string>
#include <iostream>

using namespace std;

Artwork::Artwork() {
    title = "unknown";
    yearCreated = -1;
    artist = Artist();
}

Artwork::Artwork(string title, int yearCreated, Artist artist) {
    this->title = title;
    this->yearCreated = yearCreated;
    this->artist = artist;
}

string Artwork::GetTitle() const
{
    return title;
}

int Artwork::GetYearCreated() const
{
    return yearCreated;
}

void Artwork::PrintInfo() const {
    artist.PrintInfo();
    cout << "Title: " << title << ", " << yearCreated << endl;
}
