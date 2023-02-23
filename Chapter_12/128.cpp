#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

/*
A pedometer treats walking 2,000 steps as walking 1 mile. Write a StepsToMiles() function that takes the number of steps as an integer parameter and returns the miles walked as a double. The StepsToMiles() function throws a runtime_error object with the message "Exception: Negative step count entered." when the number of steps is negative. Complete the main() function that reads the number of steps from a user, calls the StepsToMiles() function, and outputs the returned value from the StepsToMiles() function. Use a try-catch block to catch any runtime_error object thrown by the StepsToMiles() function and output the exception message.

Output each floating-point value with two digits after the decimal point, which can be achieved by executing
cout << fixed << setprecision(2); once before all other cout statements.*/

/* Define your function here */

double StepsToMiles(int steps)
{
    if (steps < 0)
    {
        

        throw runtime_error("Exception: Negative step count entered.");
    }
    return steps / 2000.0;
}

int main()
{

    /* Type your code here. */
    int steps;
    

    try
    {
        cin >> steps;
        cout << fixed << setprecision(2) << StepsToMiles(steps) << endl;
    }
    catch (ios_base::failure &e)
    {
        cout << e.what() << endl;
    }
    catch (runtime_error &e)
    {
        cout << e.what() << endl;
        return 0;
    }

    return 0;
}
