#include <iostream>
using namespace std;

int comparisons = 0;
int global_size;
// Create an array of size ints.

// Read size ints from cin, storing them in the array.
// Return the array.
int *ReadNums(int size)
{
    int *nums = new int[size]; // Create array
    for (int i = 0; i < size; ++i)
    { // Read the numbers
        cin >> nums[i];
    }
    return nums; // Return the array
}

// Output the numbers in nums, separated by spaces.
// No space or newline will be output before the first number or after the last.
void PrintNums(int nums[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << nums[i];
        if (i < size - 1)
        { // No space after last number
            cout << " ";
        }
    }
    cout << endl;
}

void Merge(int numbers[], int i, int j, int k)
{
    int mergedSize;
    int mergePos;
    int leftPos;
    int rightPos;
    int *mergedNumbers = nullptr;

    mergePos = 0;
    mergedSize = k - i + 1;
    leftPos = i;
    rightPos = j + 1;
    mergedNumbers = new int[mergedSize];

    while (leftPos <= j && rightPos <= k)
    {
        if (numbers[leftPos] < numbers[rightPos])
        {
            mergedNumbers[mergePos] = numbers[leftPos];
            ++leftPos;
            //comparisons++;
        }
        else
        {
            mergedNumbers[mergePos] = numbers[rightPos];
            ++rightPos;
            //comparisons++;
        }
        ++mergePos;
    }

    while (leftPos <= j)
    {
        mergedNumbers[mergePos] = numbers[leftPos];
        ++leftPos;
        ++mergePos;
        //comparisons++;
    }

    while (rightPos <= k)
    {
        mergedNumbers[mergePos] = numbers[rightPos];
        ++rightPos;
        ++mergePos;
        //comparisons++;
    }

    for (mergePos = 0; mergePos < mergedSize; ++mergePos)
    {
        
        numbers[i + mergePos] = mergedNumbers[mergePos];
    }
    delete[] mergedNumbers;
}

void MergeSort(int numbers[], int i, int k)
{
    cout << "recursion" << endl;
    int j;

    if (i < k)
    {
        j = (i + k) / 2;
        /* Trace output added to code in book */
        cout << i << " " << j << " | " << j + 1 << " " << k << endl;

        MergeSort(numbers, i, j);
        MergeSort(numbers, j + 1, k);

        Merge(numbers, i, j, k);
    }
}

int main()
{

    /*
    Add code to the merge sort algorithm to count the number of comparisons performed.
    Add code at the end of main() that outputs "comparisons: " followed by the number of comparisons performed (Ex: "comparisons: 12")
    Hint: Use a global variable to count the comparisons.
    */

    cin >> global_size;
    int *numbers = ReadNums(global_size);

    cout << "unsorted: ";
    PrintNums(numbers, global_size);
    cout << endl;

    MergeSort(numbers, 0, global_size - 1);

    cout << endl
         << "sorted:   ";
    PrintNums(numbers, global_size);
    cout << "comparisons: " << comparisons / 2 << endl;
    return 0;
}
