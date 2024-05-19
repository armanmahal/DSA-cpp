// Finding the n'th term of fibonacci series using recursions
//  0,1,1,2,3,5,8,13,21,34...

#include <iostream>
using namespace std;

int fibonacci(int n)
{
    // base cases:
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }

    return ( fibonacci(n - 1) + fibonacci(n - 2) );
}

int main()
{
    int n = 6;

    cout << fibonacci(n) << endl;
}