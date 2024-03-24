/*
You are given an array consisting of n integers which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. You are given the task of assigning stalls to k cows such that the minimum distance between any two of them is the maximum possible.
The first line of input contains two space-separated integers n and k.
The second line contains n space-separated integers denoting the position of the stalls.

Example 1:

Input:
n=5
k=3
stalls = [1 2 4 8 9]
Output:
3
Explanation:
The first cow can be placed at stalls[0],
the second cow can be placed at stalls[2] and
the third cow can be placed at stalls[3].
The minimum distance between cows, in this case, is 3,
which also is the largest among all possible ways.

Example 2:

Input:
n=5
k=3
stalls = [10 1 2 7 5]
Output:
4
Explanation:
The first cow can be placed at stalls[0],
the second cow can be placed at stalls[1] and
the third cow can be placed at stalls[4].
The minimum distance between cows, in this case, is 4,
which also is the largest among all possible ways.
*/
#include <iostream>
#include <algorithm>
using namespace std;

bool isPossibleStable(int arr[], int size, int mid, int cows)
{
    // we need to sort the array to implement this solution:
    sort(arr, arr + size);

    // placing first cow in first and least numbered stable:
    int cowsRequired = 1;
    int lastPosition = arr[0];

    for (int i = 0; i < size; i++)
    {
        int currentPosition = arr[i];
        // if the distance between the stable of last cow and current cow is less than mid, then you can place the cow in next stable:
        if ((currentPosition - lastPosition) < mid)
        {
            continue;
        }
        // if the distance between the stable of last cow and current cow is equal to more than mid, than we will need to bring one more cow:
        else
        {
            cowsRequired++;
            // update the last position of cow as new cow is introduced:
            lastPosition = arr[i];
        }
    }

    // up until this point , we will know how many cows can be place with distance between them equal to more than mid.
    //  if the number of cows that can be placed according to this mid is equal to or more than the amount of cows that we require to place in stables according to the question, then return true:

    if (cowsRequired >= cows)
    {
        return true;
    }
    // else if the number of cows that can be placed into the stables according to this mid is less than the amount of cows that we need to place accoring to question , then return false:
    else
    {
        return false;
    }
}

int allocateStable(int arr[], int size, int cows)
{
    // defining the search space [0 to max number of stable possible in array]:
    int s = 0;
    int e = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > e)
        {
            e = arr[i];
        }
    }
    // initialising mid:
    int mid = s + (e - s) / 2;
    int ans = -1;

    // condition:
    while (s <= e)
    {
        // if mid is a possible solution , store it in ans ,and, search in right half as we need to get the largest answer:
        if (isPossibleStable(arr, size, mid, cows))
        {
            ans = mid;
            s = mid + 1;
        }
        // if mid is not a possible solution, then none of the numbers of right of mid is a valid possible solution, so continue the search in left half:
        else
        {
            e = mid - 1;
        }

        // reevaluting mid:
        mid = s + (e - s) / 2;
    }

    return ans;
}

int main()
{
    int arr[5] = {1, 2, 4, 8, 9};
    int n = 5;
    int k = 3;

    int arr1[5] = {10, 1, 2, 7, 5};
    int n1 = 5;
    int k1 = 3;

    cout << allocateStable(arr, n, k) << endl;
    cout << allocateStable(arr1, n1, k1) << endl;
}