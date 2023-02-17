#include <iostream>
#include <vector> 
using namespace std;

int main() {
    
    vector<int> numbers;
    while (true) {
        int temp;
        cin >> temp;
        if (temp < 0) {
            break;
        } else if (numbers.size() > 8) {
            cout << "Too many numbers" << endl;
            return 0;
        }
        numbers.push_back(temp);
    } 
    int middleIndex = numbers.size() / 2;

    cout << "Middle item: " << numbers[middleIndex] << endl;
}