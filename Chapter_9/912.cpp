#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

char grade(double i)
{
    i = (i > 100) ? 100 : i;
    i = (i < 0) ? 0 : i;
    int j = i / 10;

    switch (j)
    {
    case 9:
        return 'A';
    case 8:
        return 'B';
    case 7:
        return 'C';
    case 6:
        return 'D';
    default:
        return 'F';
    }
}

void CalculateAverages(const vector<vector<int>> &allExams, vector<double> &finalAverages)
{

    for (unsigned int i = 0; i < allExams.size(); i++)
    {
        for (unsigned int j = 0; j < allExams.at(i).size(); j++)
        {
            finalAverages.at(j) += allExams.at(i).at(j);
        }
    }
    for (unsigned int i = 0; i < finalAverages.size(); i++)
    {
        finalAverages.at(i) = finalAverages.at(i) / allExams.size();
    }
}

int main()
{
    ifstream inFS;
    string fileName;
    string line;
    string firstName;
    string lastName;
    vector<vector<int>> allExams;
    vector<double> finalAverages(3);

    unsigned int i;
    // output stream
    ofstream outFS;
    outFS.open("report.txt");

    cin >> fileName;

    inFS.open(fileName);
    if (inFS.is_open())
    {

        getline(inFS, line);
        while (!inFS.eof())
        {
            if (line.find("\t") != string::npos)
            {
                istringstream iss(line);
                vector<int> exams(3);

                getline(iss, lastName, '\t');
                getline(iss, firstName, '\t');
                iss >> exams.at(0);
                iss >> exams.at(1);
                iss >> exams.at(2);

                int sum = 0;
                for (i = 0; i < exams.size(); i++)
                {
                    sum += exams.at(i);
                }
                double average = sum / 3;
                allExams.push_back(exams);
                outFS << line << "\t" << grade(average) << endl;
            }
            getline(inFS, line);
        }
        inFS.close();
    }
    CalculateAverages(allExams, finalAverages);
    outFS << endl
          << fixed << setprecision(2) << "Averages: midterm1 " << finalAverages.at(0) << ", midterm2 " << finalAverages.at(1) << ", final " << finalAverages.at(2) << endl;
    return 0;
}
