#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int recursions = 0;
int comparisons = 0;
// Read integers from input and store them in a vector.
// Return the vector.
vector<int> ReadIntegers()
{
    int size;
    cin >> size;
    vector<int> integers(size);
    for (int i = 0; i < size; ++i)
    { // Read the numbers
        cin >> integers.at(i);
    }
    sort(integers.begin(), integers.end());
    return integers;
}

int BinarySearch(int target, vector<int> vec, int left, int right)

// int BinarySearch(vector<shared_ptr<Customer>> vec, int CustomerID)
{
    recursions++;
    comparisons++;
    if (left<=right) {
        int mid = left + (right - left) / 2;
        comparisons++;
        if (vec[mid] == target)
        {
            return mid;
        }
        else if (vec[mid] < target)
        {
            
            left = mid + 1;
            return BinarySearch(target, vec,left,right);
        }
        else
        {
               right = mid - 1;
            return BinarySearch(target, vec, left, right);
        }
    }


    return -1;
}

int main()
{
    int target;
    int index;

    vector<int> integers = ReadIntegers();

    cin >> target;

    index = BinarySearch(target, integers, 0, integers.size() - 1);
    printf("index: %d, recursions: %d, comparisons: %d\n",
           index, recursions, comparisons);

    return 0;
}
