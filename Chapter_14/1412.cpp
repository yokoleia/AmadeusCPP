#include <queue>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string personName = "";
    int counter = 0;
    int youPosition;

    queue<string> peopleInQueue;

    getline(cin, personName);
    while (personName != "-1")
    {
        // TODO: Add personName to peopleInQueue
        //       determine position of "You" (youPosition)
        peopleInQueue.emplace(personName);
        counter++;
        youPosition = (personName == "You") ? counter : youPosition;
        getline(cin, personName);

    }

    cout << "Welcome to the ticketing service... " << endl;
    cout << "You are number " << youPosition << " in the queue." << endl;

    // TODO: In a loop, remove head person from peopleInQueue,
    //       output their name and that they have purchased a ticket,
    //       then output your position in the queue. When you are at
    //       the head, output that you can purchase your ticket.

    while (youPosition > 1) {
        youPosition--;
        string head = peopleInQueue.front();
        peopleInQueue.pop();
        
        cout << head << " has purchased a ticket." << endl;
        
        cout << "You are now number " << youPosition << endl;
        
    }
    cout << "You can now purchase your ticket!" << endl;
    return 0;
}