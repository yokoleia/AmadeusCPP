#include "Team.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;


void Team::SetName(string name) {
    this->name = name;
}

void Team::SetWins(int wins){
    this->wins = wins;

}

void Team::SetLosses(int losses) {
    this-> losses = losses;
}
string Team::GetName() {
    return this->name;
}
int Team::GetWins() {
    return this->wins;
}
int Team::GetLosses() {
    return this->losses;
}
double Team::GetWinPercentage() {
    return ((double)this->wins) / (wins + losses);
}
void const Team::PrintStanding() {
    double winPercentage = this->GetWinPercentage();
    cout << fixed << setprecision(2);
    cout << "Win percentage: " << winPercentage << endl;
    if (winPercentage < 0.5) {
        cout << "Team " << this->name << " has a losing average." << endl;
    } else {
        cout << "Congratulations, Team " << this->name << " has a winning average!" << endl;
    }
}