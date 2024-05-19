/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

#include <iostream>
using namespace std;

int numberOfWaysToClimbCurrentStair(int n)
{
    // base cases:
    // when you reach the bottom most stair:
    if (n == 0)
    {
        return 1;
    }
    // if you go beyond the bottom most stair:
    if (n < 0)
    {
        return 0;
    }

    return (numberOfWaysToClimbCurrentStair(n - 1) + numberOfWaysToClimbCurrentStair(n - 2));
}

int main()
{
    int stairsToClimb = 3;

    cout << numberOfWaysToClimbCurrentStair(3) << endl;
}