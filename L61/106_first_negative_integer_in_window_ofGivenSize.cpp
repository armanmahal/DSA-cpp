// STATEMENT:
/*
Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.
*/
/*
Example 1:

Input :
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output :
-8 0 -6 -6
Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6

Example 2:
Input :
N = 8
A[] = {12, -1, -7, 8, -15, 30, 16, 28}
K = 3
Output :
-1 -1 -7 -15 -15 0
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// APPROACH 1: Bruteforce
void solve(int *arr, int size, int k)
{
    for (int i = 0; i <= size - k; i++)
    {
        bool negativeFound = false;
        for (int j = 0; j < k; j++)
        {

            int element = arr[i + j];
            if (element < 0)
            {
                cout << element << " ";
                negativeFound = true;
                break;
            }
        }
        if (negativeFound == false)
        {
            cout << 0 << " ";
        }
    }
    cout << endl;
}

// APPROACH 2: use a deque:
void solve2(int *arr, int size, int k)
{
    // create a deque:
    deque<int> q;
    // create a vector for ans:
    vector<int> ans;

    // process first window of k size to find any negative elments:
    for (int i = 0; i < k; i++)
    {
        // if any negative element found, store its index in deque:
        if (arr[i] < 0)
        {
            q.push_back(i);
        }
    }
    // if there is some negative elment in the first window of k size:
    if (!q.empty())
    {
        ans.push_back(arr[q.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    // process the remaining windows:
    for (int i = k; i < size; i++)
    {
        // remove the front index of deque if its out of the current window:
        if (!q.empty() && q.front() <= i - k)
        {
            q.pop_front();
        }

        // addition of index of current element if its negative:
        if (arr[i] < 0)
        {
            q.push_back(i);
        }

        // storing the answer:
        if (!q.empty())
        {
            ans.push_back(arr[q.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }

    // printing the answer:
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size = 8;
    int arr[8] = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;

    solve(arr, size, k);
    solve2(arr, size, k);

    int size2 = 5;
    int arr2[size2] = {-8, 2, 3, -6, 10};
    int k2 = 2;

    solve(arr2, size2, k2);
    solve2(arr2, size2, k2);
}