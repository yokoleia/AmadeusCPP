#include <iostream>
using namespace std;

/* TODO: Write recursive DigitCount() function here.
Write a recursive function called DigitCount() that takes a positive integer as a parameter and returns the number of digits in the integer. Hint: The number of digits increases by 1 whenever the input number is divided by 10.

Ex: If the input is:

345
the function DigitCount() returns and the program outputs:

3
*/

int DigitCount(int num) {
    //9 = 1; i.e. (9/10)+1
    if ((num / 10)+1 == 1) {
        return 1;
    } else {
        return 1+DigitCount(num/10);
    }
    
}

    int
    main()
{
    int num;
    int digits;

    cin >> num;
    digits = DigitCount(num);
    cout << digits << endl;
    return 0;
}
