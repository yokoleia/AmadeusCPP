#include <iostream>
using namespace std;

int main() {
    char ch;
    cin >> ch;
    switch (ch) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            cout << "Vowel: " << ch;
            break;
        default: 
            cout << "Consonant: " << ch;
            break;
    } 
    
}