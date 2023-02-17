#ifndef FOODITEMH
#define FOODITEMH

#include <string>
using namespace std;

class FoodItem {
    private:
        string name;
        double gramsFat;
        double gramsCarbs;
        double gramsProtein;
        
    public:
        FoodItem();
        FoodItem(string name, double gramsFat, double gramsCarbs, double gramsProtein);

        string GetName() const;

        double GetFat() const;

        double GetCarbs() const;

        double GetProtein() const;

        double GetCalories(double numServings);

        void PrintInfo() const;
};



#endif