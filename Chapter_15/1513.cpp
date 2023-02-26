#include <iostream>
using namespace std;

// Read size numbers from cin into a new array and return the array.
int *ReadNums(int size)
{
    int *nums = new int[size]; // Create array
    for (int i = 0; i < size; ++i)
    { // Read the numbers
        cin >> nums[i];
    }
    return nums;
}

// Print the numbers in the array, separated by spaces
// (No space or newline before the first number or after the last.)
void PrintNums(int nums[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << nums[i];
        if (i < size - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
}

// Exchange nums[j] and nums[k].
void Swap(int nums[], int j, int k)
{

    int temp;
    temp = nums[j];
    nums[j] = nums[k];
    nums[k] = temp;
}

// Sort numbers
/* TODO: Count comparisons and swaps.
         Output the array at the end of each iteration. */
void InsertionSort(int numbers[], int size, int &swaps, int &comparisons)
{
    int i;
    int j;

    for (i = 1; i < size; ++i)
    {
        j = i;
        while (j > 0 && numbers[j] < numbers[j - 1])
        {
            Swap(numbers, j, j - 1);
            swaps += 1;
            comparisons += 1; // increment comparison count
            --j;
        }
        if (j != 0)
        {
            comparisons++;
        }
        PrintNums(numbers, size);
    }
}

int main()
{
    // Step 1: Read numbers into an array
    int size;
    int comparisons = 0;
    int swaps = 0;
    cin >> size;                   // Read array size
    int *numbers = ReadNums(size); // Read numbers

    // Step 2: Output the numbers array
    PrintNums(numbers, size);
    cout << endl;

    // Step 3: Sort the numbers array
    InsertionSort(numbers, size, swaps, comparisons);
    cout << endl;

    // Step 4: Output the number of comparisons and swaps
    // comparisons = (size*(size-1)/2)/2;
    cout << "comparisons: " << comparisons << endl;
    cout << "swaps: " << swaps << endl;
    /* TODO: Output the number of comparisons and swaps performed */

    return 0;
}
