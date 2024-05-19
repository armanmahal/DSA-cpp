// finding sum of elements of array using recursions:

#include <iostream>
using namespace std;

int findSum(int arr[], int size)
{

    int sum = 0;

    // base case:
    if (size == 0)
    {
        return 0;
    }
    if (size == 1)
    {
        return arr[0];
    }

    sum = arr[0] + findSum(arr + 1, size - 1);

    return sum;
}

int main()
{
    int arr[6] = {1, 2, 3, 6, 7, 9};
    int arr2[5] = {1, 2, 3, 6, 4};

    cout << findSum(arr, 6) << endl;
    cout << findSum(arr2, 5) << endl;
}