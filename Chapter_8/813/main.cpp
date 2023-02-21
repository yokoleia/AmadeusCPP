#include "MileageTrackerNode.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
    // References for MileageTrackerNode objects
    MileageTrackerNode *headNode;
    MileageTrackerNode *currNode;
    MileageTrackerNode *lastNode;

    double miles;
    string date;
    int i;

    // Front of nodes list
    headNode = new MileageTrackerNode();
    lastNode = headNode;
    int numNodes;
    // TODO: Read in the number of nodes
    cin >> numNodes;

    // TODO: For the read in number of nodes, read
    //       in data and insert into the linked list
    for (i=0; i<numNodes; i++) {
        cin >> miles >> date;
        currNode = new MileageTrackerNode(miles, date);
        lastNode->InsertAfter(currNode);
        lastNode = currNode;
    }
    
    currNode = headNode->GetNext();
    //currNode = headNode->GetNext();
    while (currNode != nullptr) {
        //currNode = headNode->GetNext();
        currNode->PrintNodeData();
        currNode = currNode->GetNext();
    }
        // TODO: Call the PrintNodeData() method
        //       to print the entire linked list

        // MileageTrackerNode Destructor deletes all
        //       following nodes
        delete headNode;
}