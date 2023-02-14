#include <iostream>
using namespace std;


int main() {

    int interstateNumber, auxServing;
    string interstateType, interstateDirection;


    cin >> interstateNumber;

    interstateDirection = (interstateNumber % 2 == 0) ? "east/west" : "north/south";
    if ((interstateNumber > 0) && (interstateNumber < 100)) {
        interstateType = "primary";
        cout << "I-" << interstateNumber << " is " << interstateType << ", going " << interstateDirection;
    } else if ((interstateNumber > 99) && (interstateNumber < 1000)) {
        interstateType = "auxiliary";
        auxServing = interstateNumber % 100;
        if (((auxServing > 0) && (auxServing < 100)))
        {
            cout << "I-" << interstateNumber << " is " << interstateType << ", serving I-" << auxServing << ", going " << interstateDirection;
        } else {
            cout << interstateNumber << " is not a valid interstate highway number";
        }
    } else {
        cout << interstateNumber << " is not a valid interstate highway number";
    }

    
    cout << "." << endl;



    

    return 0;
}