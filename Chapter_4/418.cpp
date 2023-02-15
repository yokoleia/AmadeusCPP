#include <iostream>
using namespace std;

int main() {

   /* Type your code here. */
   int lower, higher;
   
   cin >> lower >> higher;
   if (higher < lower) {
      cout << "Second integer can't be less than the first." << endl;
   } else {
      
      while (lower <= higher) {
         cout << lower << " ";
         lower += 5;
      }
      cout << endl;
   }
   

   return 0;
}
