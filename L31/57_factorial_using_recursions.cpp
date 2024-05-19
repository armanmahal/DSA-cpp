// finding factorial of a number using recursions

#include <iostream>
using namespace std;

int factorial(int n)
{
    // base case:
    if (n == 1 || n == 0)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

int main()
{
    int x = 5;
    cout << factorial(x) << endl;
}