#include "Flower.h"
#include "Plant.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

// TODO: Define a PrintVector function that prints an vector of plant (or flower) object pointers
void PrintVector(vector<Plant*> myGarden) {
    for (int i = 0; i < myGarden.size(); i++)
    {
        cout << "Plant " << i << " Information:" << endl;
        myGarden[i]->PrintInfo();
        cout << endl;
    }
}

int main()
{
    // TODO: Declare a vector called myGarden that can hold object of type plant pointer
    vector<Plant*> myGarden;
    // TODO: Declare variables - 
    string plantName;
    int plantCost;

    string flowerName;
    int flowerCost;
    string colorOfFlowers;
    bool isAnnual;
    
    
    
    string input;

    cin >> input;

    while (input != "-1")
    {
        
        // TODO: Check if input is a plant or flower
        //       Store as a plant object or flower object
        //       Add to the vector myGarden
        if (input == "plant") {
            cin >> plantName;
            cin >> plantCost;
            Plant *tempPlant = new Plant;
            tempPlant->SetPlantCost(plantCost);
            tempPlant->SetPlantName(plantName);
            myGarden.push_back(tempPlant);
        } else if (input == "flower") {

            Flower* tempFlower = new Flower;
            cin >> flowerName;
            cin >> flowerCost;
            string temp;
            cin >> temp;
            if (temp=="true") { isAnnual = true;} else if (temp=="false") { isAnnual = false;}
            cin >> colorOfFlowers;
            tempFlower->SetPlantName(flowerName);
            tempFlower->SetPlantCost(flowerCost);
            tempFlower->SetPlantType(isAnnual);
            tempFlower->SetColorOfFlowers(colorOfFlowers);
            myGarden.push_back(tempFlower);
        }

        
        cin >> input;
    }

    // TODO: Call the method PrintVector to print myGarden
    PrintVector(myGarden);
    for (size_t i = 0; i < myGarden.size(); ++i)
    {
        delete myGarden.at(i);
    }

    return 0;
}