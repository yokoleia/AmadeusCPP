#include <iostream>
using namespace std;

int Fibonacci(int limit)
{
    if (limit < 0) {
        return -1;
    } else if (limit == 0) {
        return 0;
    }
    int fibout;
    int i = 0;
    int n1 = 0;
    int n2 = 1;
    do
    {

        int fib = n1 + n2;
        n1 = n2;
        n2 = fib;
        fibout = fib;

        i++;
    } while (i < limit - 1);
    return fibout;
}

int main()
{
    int startNum;

    cin >> startNum;

    cout << "Fibonacci(" << startNum << ") is " << Fibonacci(startNum) << endl;
}