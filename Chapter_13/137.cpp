#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // to use sort()
using namespace std;

const int NUM_VALUES = 5;

// Input NUM_VALUES of TheType into the vector parameter
template <typename TheType>
void Read(vector<TheType> &list)
{
    for (int j = 0; j < NUM_VALUES; ++j)
    {
        cin >> list.at(j);
    }
}

// Output the elements of the vector parameter
template <typename TheType>
void Write(vector<TheType> &list)
{
    long unsigned int j;
    for (j = 0; j < list.size(); ++j)
    {
        cout << list.at(j) << " ";
    }
}

// Return the min, median, and max of the vector parameter in a new vector
template <typename TheType>
vector<TheType> GetStatistics(vector<TheType> &list)
{
    /* Type your code here. */
    vector<TheType> statistics;
    sort(list.begin(), list.end());
    statistics.push_back(list.at(0));

    if (NUM_VALUES % 2 == 0) {
        statistics.push_back(list.at(NUM_VALUES / 2 - 1));
    } else {
        statistics.push_back(list.at(NUM_VALUES / 2));
    }
    statistics.push_back(list.at(list.size()-1));
    return statistics;
}

// Read values into a vector, sort the vector, output the sorted vector,
// then output the min, median, and max of the sorted vector
template <typename TheType>
void Run(vector<TheType> &list)
{
    Read(list);
    //Write(list);
    cout << endl;
    vector<TheType> statistics = GetStatistics(list);
    Write(list);
    cout << endl;
    Write(statistics);
    cout << endl;
}

int main()
{
    vector<int> integers(NUM_VALUES);
    Run(integers);
    cout << endl;

    vector<double> doubles(NUM_VALUES);
    Run(doubles);
    cout << endl;

    vector<string> strings(NUM_VALUES);
    Run(strings);

    return 0;
}
