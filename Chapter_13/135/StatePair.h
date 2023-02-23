#ifndef STATEPAIR
#define STATEPAIR
#include <string>
using namespace std;

template <typename T1, typename T2>
class StatePair
{
    private: 
        T1 userKey;
        T2 userValue;

    public: 
        // TODO: Define constructors
        StatePair() : userKey(), userValue() {}
        StatePair(T1 key, T2 value) : userKey(key), userValue(value) {}


        // TODO: Define mutators, and accessors for StatePair
        void SetKey(T1 Key) {
            userKey = Key;
        }

        void SetValue(T2 Value)
        {
            userValue = Value;
        }
        T1 GetKey() {
            return userKey;
        }

        T2 GetValue() {
            return userValue;
        }

        // TODO: Define PrintInfo() method
        void PrintInfo() {
            cout << userKey << ": " << userValue << endl;

        }
};
/*
template <typename T1, typename T2>
StatePair<T1, T2>::StatePair(T1 userKey, T2 userValue)
{
        this->userKey = userKey;
        this->userValue = userValue;
}*/

#endif