// given an integer, find the number of 1bits in the binary form of that integer

#include <iostream>
using namespace std;

int main()
{
    cout << "Enter the Number: ";
    int n;
    cin >> n;

    int count = 0;

    // run the loop until the number becomes zero
    while (n != 0)
    {

        // to get the last bit of any number do binary AND of it and 1 {n&1}

        //                EXAMPLE1:
        //      0000 0000 0000 0000 0000 0000 0000 0101  (5)
        //      &
        //      0000 0000 0000 0000 0000 0000 0000 0001  (1)
        //      ------------------------------------------
        //      0000 0000 0000 0000 0000 0000 0000 0001  (1)

        //                EXAMPLE2:
        //      0000 0000 0000 0000 0000 0000 0000 0010  (2)
        //      &
        //      0000 0000 0000 0000 0000 0000 0000 0001  (1)
        //------------------------------------------
        //      0000 0000 0000 0000 0000 0000 0000 0000  (0)


        int bit = n & 1;

        // if bit is 1, increase the count by one
        if (bit == 1)
        {
            count++;
        }

        // shift the last bit of number to right to get the next bit
        n = n >> 1;
    }

    // print the answer
    cout << count << endl;
}