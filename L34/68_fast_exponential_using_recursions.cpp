// fine the exponential of a number using recursions (using fast exponential method- Lecture-24, Problem-54)

#include <iostream>
using namespace std;

int fastExponential(int base, int power)
{
    // base case:
    if (power == 1)
    {
        return base;
    }

    // recursive call :
    // to find- (base^power/2) :
    int ans = fastExponential(base, power / 2);

    if (power & 1)
    {
        // power is odd:
        // then answer = [ base * (base^power/2) * (base^power/2) ]
        return ans * ans * base;
    }
    else
    {
        // power is even:
        // then answer = [ (base^power/2) * (base^power/2) ]
        return ans * ans;
    }
}

int main()
{
    cout << fastExponential(3, 5) << endl;
    cout << fastExponential(2, 4) << endl;
    cout << fastExponential(2, 5) << endl;
}