// given an array of size - n , it has all the integer from range [1, n-1],
//  the one space that is left in the array is occupied by any integer from [1, n-1],,
//  find this one duplicate integer.
#include <iostream>
using namespace std;

void printDuplicate(int arr[], int size)
{

    int ans = 0;

    // XORing first element of array as it will not be covered in loop
    ans = ans ^ arr[0];

    // loop to XOR all the elements of array {except arr[0]} and all integers from [1 to size-1]
    for (int i = 1; i < size - 1; i++)
    {
        ans = ans ^ arr[i] ^ i;
    }

    cout << ans << endl;
}

int main()
{
    int array[8] = {1, 2, 4, 3, 5, 2, 6, 7};

    printDuplicate(array, 8);
}