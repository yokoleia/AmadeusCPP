#ifndef TEAMH
#define TEAMH

#include <string>
using namespace std;

class Team
{
private:
    int wins = 0;
    int losses = 0;
    string name;

public:
    void SetName(string name);
    void SetWins(int wins);
    void SetLosses(int losses);
    string GetName();
    int GetWins();
    int GetLosses();
    double GetWinPercentage();
    void const PrintStanding();
};
#endif