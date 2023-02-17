#include <iostream>
#include <cmath>
using namespace std;

int main() {
    const int LIMIT = 100;
    int count = 1;
    cout << "2, ";

    for (int i = 3; i < LIMIT; i=i+2) {
        bool isPrime = true;
        for (int j = 2; j < sqrt(i)+1; j++) {
            if (i%j==0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            count++;
            cout << i << ", ";
            
        }
    }
    cout << endl << count << " primes" << endl;
}