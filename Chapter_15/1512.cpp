#include <string>
#include <vector>
#include <iostream>

using namespace std;

// TODO: Write the partitioning algorithm - pick the middle element as the
//       pivot, compare the values using two index variables l and h (low and high),
//       initialized to the left and right sides of the current elements being sorted,
//       and determine if a swap is necessary
int Partition(vector<string> &userIDs, int i, int k)
{
    int l = i;
    int h = k;
    string pivot = userIDs[(i + k) / 2]; // pick the middle element as the pivot

    while (l <= h)
    {
        while (userIDs[l] < pivot)
        {
            l++;
        }
        while (userIDs[h] > pivot)
        {
            h--;
        }
        if (l <= h)
        {
            swap(userIDs[l], userIDs[h]); // swap the elements at indices l and h
            l++;
            h--;
        }
    }
    return l;
}

// TODO: Write the quicksort algorithm that recursively sorts the low and
//       high partitions
void Quicksort(vector<string> &userIDs, int i, int k)
{
    if (i >= k)
    {
        return; // base case: array is sorted when i >= k
    }
    int index = Partition(userIDs, i, k); // partition the array around a pivot
    Quicksort(userIDs, i, index - 1);     // recursively sort the low partition
    Quicksort(userIDs, index, k);         // recursively sort the high partition
}

int main()
{
    vector<string> userIDList;
    string userID;

    cin >> userID;
    while (userID != "-1")
    {
        userIDList.push_back(userID);
        cin >> userID;
    }

    // Initial call to quicksort
    Quicksort(userIDList, 0, userIDList.size() - 1);

    for (size_t i = 0; i < userIDList.size(); ++i)
    {
        cout << userIDList.at(i) << endl;
        ;
    }

    return 0;
}