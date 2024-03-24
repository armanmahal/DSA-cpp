// given an integer array , it has only one element that occurs only ones
//  the rest elements occur an exactly two times
//  find the element that occurs one time.

#include <iostream>
using namespace std;

int findUnique(int array[], int size)
{

    int ans = 0;

    for (int i = 0; i < size; i++)
    {
        ans = ans ^ array[i];
    }

    return ans;
}

int main()
{

    int arr[11] = {10, 3, 4, 5, 10, 4, 2, 3, 2, 7, 7};

    int uniqueElement = findUnique(arr, 11);

    cout << uniqueElement << endl;
}