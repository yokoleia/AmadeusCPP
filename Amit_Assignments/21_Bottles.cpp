#include <iostream>
using namespace std;
int getFirstPlayer() {
    cout << "Would you like to play first (Yes/No)" << endl;
    string response; 
    cin >> response;

    // if 0- CPU, 1-Human
    if (response == "Yes") {
        return 1;
    } else if (response == "No") {
        return 0;
    } else {
        cout << "Invalid Selection" << endl;
        return getFirstPlayer();
    }
}

int takePlayerInput() {
    int numBottles;
    
    cin >> numBottles;
    if ((numBottles <= 4) && (numBottles > 0))
    {
        return numBottles;
    }
    else
    {
        cout << "Invalid Selection" << endl;
        return takePlayerInput();
    }
}

int takeCPUInput(int remainingBottles) {
    if (((remainingBottles - 1) % 5) == 0)
    {
        return 1;
    }
    else
    {
        return ((remainingBottles - 1) % 5);
    }
}

void gameOverResult(int remainingBottles) {
    if (remainingBottles == 1) {
        cout << "You have to pick up the last bottle!\nGame over! You Lost!" << endl;
    } else {
        cout << "Computer has picked up the last bottle! You Won!" << endl;
    }
}

int main() {
    bool gameOver = false;
    int remainingBottles = 21;
    int cpuInput;
    cout << "There are " << remainingBottles << " beer bottles..." << endl;
    cout << "You vs CPU." << endl;
    cout << "Each player can pick up any number of bottles between 1 and 4 (inclusive)" << endl;
    cout << "Don't be the last player to pick up or you'll lose. " << endl;
    
    int firstPlayer = getFirstPlayer(); // if 0- CPU, 1-Human
    bool CPUfirstRound = false;

    if (firstPlayer == 1) {
        cout << "You have selected to play First!" << endl;
    } else {
        CPUfirstRound = true;
        cout << "Ok! You have selected to play Second! Computer will play First!" << endl;
    }
    while (!gameOver)
    {
        if (CPUfirstRound) {
            CPUfirstRound = false;
            cpuInput = takeCPUInput(remainingBottles);
            cout << "Computer has picked up: " << cpuInput << endl;
            remainingBottles -= cpuInput;
        }

        cout << "Bottles remaining are: " << remainingBottles << endl;
        cout << "How many would you like to pickup. " << endl;
        remainingBottles -= takePlayerInput();
        cpuInput = takeCPUInput(remainingBottles);
        cout << "Computer has picked up: " << cpuInput << endl;
        remainingBottles -= cpuInput;
        if (remainingBottles <= 1)
        {
            gameOver = true;
        }
    }
    gameOverResult(remainingBottles);
    return 0;
}