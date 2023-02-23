#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <utility>
#include <vector>
#include <string>
using namespace std;

class Movie
{
public:
    string Name;
    string Rating;
    vector<string> Showtimes;

    Movie(string movieName, string rating)
    {
        this->Name = std::move(movieName);
        this->Rating = std::move(rating);
    }
    void printMovieDetails() const
    {
        cout << "Name: " << this->Name << "\nRating: " << this->Rating << endl;
    }
};

class Cinema
{
private:
    vector<Movie> Movies;

public:
    bool movieInCinema(const string &MovieName)
    {
        for (auto &Movie : Movies)
        {
            if (Movie.Name == MovieName)
            {
                return true;
            }
        }
        return false;
    }
    void addMovie(const Movie &movie)
    {
        this->Movies.push_back(movie);
    }
    void printSessions()
    {
        for (auto &Movie : Movies)
        {
            string outputName = Movie.Name;
            if (outputName.length() > 44)
            {
                outputName = outputName.substr(0, 44);
            }
            cout << setw(44) << left << outputName << " | ";
            cout << setw(5) << right << Movie.Rating << " |";
            for (auto &time : Movie.Showtimes)
            {
                cout << " " << time;
            }
            cout << endl;
        }
    }
    void addShowtime(const string &movieName, const string &showtime)
    {
        for (auto &Movie : Movies)
        {
            if (Movie.Name == movieName)
            {
                Movie.Showtimes.push_back(showtime);
            }
        }
    }
};

int main()
{

    /* Type your code here.
     *  The program first reads the name of the CSV file from the user.
     *  The program then reads the CSV file and outputs the contents according to the following requirements:

         *  Each row contains the title, rating, and all showtimes of a unique Movie.
         *  A space is placed before and after each vertical separator ('|') in each row.
         *  Column 1 displays the Movie titles and is left justified with a minimum of 44 characters.
         *  If the Movie title has more than 44 characters, output the first 44 characters only.
         *  Column 2 displays the Movie ratings and is right justified with a minimum of 5 characters.
         *  Column 3 displays all the showtimes of the same Movie, separated by a space.
     * */

    Cinema myCinema;

    string filepath;
    cin >> filepath;
    filepath = "" + filepath;
    ifstream fileStream(filepath);

    string movieLine;
    if (!fileStream.is_open())
    {
        cout << ("File Not Open");
    }
    // Use a while loop together with the getline() function to read the file line by line
    while (getline(fileStream, movieLine))
    {
        string delimiter = ",";
        string showtime;
        string movieName;
        string movieRating;

        showtime = movieLine.substr(0, movieLine.find(delimiter));
        movieLine.erase(0, movieLine.find(delimiter) + delimiter.length());

        movieName = movieLine.substr(0, movieLine.find(delimiter));
        movieLine.erase(0, movieLine.find(delimiter) + delimiter.length());

        movieRating = movieLine.substr(0, movieLine.find(delimiter));
        movieLine.erase(0, movieLine.find(delimiter) + delimiter.length());

        if (!myCinema.movieInCinema(movieName))
        {

            Movie currentMovie = Movie(movieName, movieRating);

            currentMovie.Showtimes.push_back(showtime);
            myCinema.addMovie(currentMovie);
        }
        else
        {
            myCinema.addShowtime(movieName, showtime);
        }
    }
    myCinema.printSessions();
    fileStream.close();

    return 0;
}
