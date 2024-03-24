// given two arrays , find the intersection of those ,
//  i.e: the elements common to them both
//  {1,2,2,2,3,4} + {2,2,3,3} ---> {2,2,3}

#include <iostream>
using namespace std;

void checkIntersection(int arr1[], int size1, int arr2[], int size2)
{
    int i = 0, j = 0;

    while ((i < size1) && (j < size2))
    {
        if (arr1[i] == arr2[j])
        {
            cout << arr1[i] << ' ';
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    cout << endl;
}

int main()
{
    int arr1[6] = {1, 2, 2, 2, 3, 4};
    int arr2[4] = {2, 2, 3, 3};

    checkIntersection(arr1, 6, arr2, 4);
}