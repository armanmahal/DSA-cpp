// given two integers : x , n , m : find (x^n)%m , i.e: exponential modulo m

#include <iostream>
using namespace std;

int exponential(int x, int n, int m)
{
    int res = 1;

    for (int i = 0; i < n; i++)
    {
        // as (res*x)%m = ((res%m)*(x%m))%m
        res = ((res % m) * (x % m)) % m;
    }

    return res;
}

int fastExponential(int x, int n, int m)
{

    int res = 1;

    while (n > 0)
    {
        // if n is odd:
        if (n & 1)
        {
            // as (res*m)%m = ((res%m)*(x%m))%m
            res = ((res % m) * (x % m)) % m;
        }

        // as (x*x)%m = ((x%m)*(x%m))%m
        x = ((x % m) * (x % m)) % m;

        // dividing n by two:
        //  {n>>1---> right shifting an integer by one means to divide it by two}
        n = n >> 1;
    }

    return res;
}

int main()
{
    int x = 2;
    int n = 5;
    int m = 40;

    int moduloAnswerByFastExponential = fastExponential(x, n, m);
    int moduloAnswerByExponential = exponential(x, n, m);

    cout << moduloAnswerByFastExponential << endl;
    cout << moduloAnswerByExponential << endl;
}