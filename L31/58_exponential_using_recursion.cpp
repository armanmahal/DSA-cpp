// finding power of 2 using recursions

#include <iostream>
using namespace std;

int twoToPower(int power)
{
    if (power == 0)
    {
        return 1;
    }

    return 2 * twoToPower(power - 1);
}

int main()
{
    int power = 5;

    cout << twoToPower(5) << endl;
}