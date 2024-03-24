// given an array and an integer "S" ,
//  find all the pair of integers from the array whose sum equals to 'S'
// eg: {1,2,3,4,5} ; S=5 ---> {{1,4},{2,3}}

#include <iostream>
using namespace std;

void findPairs(int arr[], int size, int sum)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if ((arr[i] + arr[j]) == sum)
            {
                cout << "(" << arr[i] << "," << arr[j] << ")" << endl;
            }
        }
    }
    cout << endl;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int sum = 5;

    findPairs(arr, 5, sum);
}