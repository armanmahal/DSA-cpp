// given two integers m and n , find m^n using fast exponential method:
// TIME COMPLEXITY->   O(logn)

#include <iostream>
using namespace std;

int exponential(int m, int n)
{
    int res = 1;

    for (int i = 0; i < n; i++)
    {
        res = res * m;
    }

    return res;
} // TIME COMPLEXITY: O(n)

int fastExponential(int m, int n)
{

    int res = 1;

    while (n > 0)
    {
        // if n is odd:
        if (n & 1)
        {
            res = res * m;
        }

        m = m * m;

        // dividing n by two:
        //  {n>>1---> right shifting an integer by one means to divide it by two}
        n = n >> 1;
    }

    return res;
} // TIME COMPLEXITY: O(logn)

int main()
{
    int m = 3;
    int n = 7;

    int ansByExponential = exponential(m, n);         // TIME COMPLEXITY: O(n)
    int ansByFastExponential = fastExponential(m, n); // TIME COMPLEXITY: O(logn)

    cout << ansByExponential << " " << ansByFastExponential << endl;
}