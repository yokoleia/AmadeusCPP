#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int age; 
    int weight;
    int heartRate;
    int time;
    cin >> age >> weight >> heartRate >> time; 

    double calories = ( (age * 0.2757) + (weight * 0.03295) + (heartRate * 1.0781) - 75.4991 ) * time / 8.368;

    cout << "Calories: " << fixed << setprecision(2) << calories << " calories" << endl;
    return 0;
}