#include <iostream>
#include <iomanip>
using namespace std;

/* TODO: Write recursive DrawTriangle() function here.
11.14 LAB: Drawing a right side up triangle
Write a recursive function called DrawTriangle() that outputs lines of '*' to form a right side up isosceles triangle. Function DrawTriangle() has one parameter, an integer representing the base length of the triangle. Assume the base length is always odd and less than 20. Output 9 spaces before the first '*' on the first line for correct formatting.

Hint: The number of '*' increases by 2 for every line drawn.

Ex: If the input of the program is:

3
the function DrawTriangle() outputs:

         *
        ***
Ex: If the input of the program is:

19
the function DrawTriangle() outputs:

         * = 1
        *** = 3 | 3+1/2
       ***** = 3*2-1
      ******* = 4*2 -1  
     *********
    ***********
   *************
  ***************
 *****************
*******************
Note: No space is output before the first '*' on the last line when the base length is 19.*/

void DrawTriangle(int baseLength) {
    // base case
    if (baseLength == 1) {
        cout << setw(10) << "*" << endl;
    } else if (baseLength <= 19) {
        DrawTriangle(baseLength-2);
        int spaces =( (19 - baseLength)/2 )+1; // 
        cout << setw(spaces);
        for (int i=0; i<(baseLength); i++) {
            cout << "*";
        }
        cout << endl;
        //cout << right << setw(spaces - baseLength) << "" << endl;
    }   
        //    if (baseLength == 1) {
}


int main()
{
    int baseLength;

    cin >> baseLength;
    DrawTriangle(baseLength);
    return 0;
}