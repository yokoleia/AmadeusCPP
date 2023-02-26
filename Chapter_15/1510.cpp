#include <iostream>

using namespace std;

// TODO: Write a void function SelectionSortDescendTrace() that takes
//       an integer array and the number of elements in the array as arguments,
//       and sorts the array into descending order.
void SelectionSortDescendTrace(int numbers[], int numElements)
{
    int i, j, maxIndex, tmp;
    for (i = 0; i < numElements - 1; ++i)
    {
        maxIndex = i;
        for (j = i + 1; j < numElements; ++j)
        {
            if (numbers[j] > numbers[maxIndex])
            {
                maxIndex = j;
            }
        }
        // swap numbers[i] and numbers[maxIndex]
        tmp = numbers[i];
        numbers[i] = numbers[maxIndex];
        numbers[maxIndex] = tmp;

        // print the current state of the array
        for (int k = 0; k < numElements; ++k)
        {
            cout << numbers[k] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int input, i = 0;
    int numElements = 0;
    int numbers[10];

    // TODO: Read in a list of up to 10 positive integers; stop when
    //       -1 is read. Then call SelectionSortDescendTrace() function.
    cin >> input;
    while (input != -1)
    {

        numbers[i] = input;
        i++;
        cin >> input;
    }
    SelectionSortDescendTrace(numbers, i);
    return 0;
}