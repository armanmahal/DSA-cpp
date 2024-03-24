/*
 given an integer, create a new integer by reversing all the digits of the previous digit,
 if the new integer exceed the range of a 32 bit integer i.e: -2^31 to 2^31-1,
 then just print zero
*/

#include <iostream>
using namespace std;

int main()
{

    cout << "Enter the Integer: ";
    int n;
    cin >> n;

    bool exceededTheLimit = false;

    int reversedInt = 0;

    while (n != 0)
    {

        // getting the last digit of the number:
        int digit = n % 10;

        // checking if the reversed Integer's value will exceed the Limit after multiplying it with 10 and adding the digit:
        if ((reversedInt < (INT32_MIN - digit) / 10) || (reversedInt > (INT32_MAX - digit) / 10))
        {
            cout << "0" << endl;
            exceededTheLimit = true;
            break;
        }

        // updating the reversed Integer value:
        reversedInt = (reversedInt * 10) + digit;

        // removing the last digit of the number:
        n = n / 10;
    }

    if (!exceededTheLimit)
    {
        cout << reversedInt << endl;
    }
}