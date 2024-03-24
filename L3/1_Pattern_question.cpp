// Print the following pattern with while loop

//    1234554321
//    1234**4321
//    123****321
//    12******21
//    1********1

#include <iostream>
using namespace std;

int main()
{
    int x;
    cout << "Enter the height of the pattern: ";
    cin >> x;

    int i = 0;

    while (i < x)
    {

        int j = 1;
        int k = 0;

        while (j <= (x - i))
        {
            cout << j;
            j++;
        }

        j--;

        while (k < i)
        {
            cout << "**";
            k++;
        }

        while (j > 0)
        {
            cout << j;
            j--;
        }

        cout << endl;

        i++;
    }
}