#include "FoodItem.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

FoodItem::FoodItem()
{
    this->name = "Water";
    this->gramsFat = 0;
    this->gramsCarbs = 0;
    this->gramsProtein = 0;

}
FoodItem::FoodItem(string name, double gramsFat, double gramsCarbs, double gramsProtein)
{
    this->name = name;
    this->gramsFat = gramsFat;
    this->gramsCarbs = gramsCarbs;
    this->gramsProtein = gramsProtein;
}

string FoodItem::GetName() const
{
    return name;
}

double FoodItem::GetFat() const
{
    return gramsFat;
}

double FoodItem::GetCarbs() const
{
    return gramsCarbs;
}

double FoodItem::GetProtein() const
{
    return gramsProtein;
}

double FoodItem::GetCalories(double numServings) {
    // Calorie formula
    double calories = ((gramsFat * 9) + (gramsCarbs * 4) + (gramsProtein * 4)) * numServings;
    return calories;
}

void FoodItem::PrintInfo() const
{
    cout << fixed << setprecision(2);
    cout << "Nutritional information per serving of " << name << ":" << endl;
    cout << "  Fat: " << gramsFat << " g" << endl;
    cout << "  Carbohydrates: " << gramsCarbs << " g" << endl;
    cout << "  Protein: " << gramsProtein << " g" << endl;
}