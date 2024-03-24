/*
The Painter’s Partition Problem
Given are N boards of with length of each given in the form of array, and K painters, such that each painter takes 1 unit of time to paint 1 unit of the board. The task is to find the minimum time to paint all boards under the constraints that any painter will only paint continuous sections of boards, say board {2, 3, 4} or only board {1} or nothing but not board {2, 4, 5}.

Examples:

Input: N = 4, A = {10, 10, 10, 10}, K = 2
Output : 20

Explanation: Here we can divide the boards into 2 equal sized partitions (Painter 1 will paint boards A1 and A2, and Painter 2 will paint boards A3 and A4). So each painter gets 20 units of board and the total time taken is 20.

Input: N = 4, A = {10, 20, 30, 40}, K = 2
Output : 60

Explanation: Since there are only 2 painters, therefore divide first 3 boards to painter 1 (A1, A2 and A3) with time = 60, and last board to painter 2 (A4) with time = 40. Therefore total time taken = 60, which is the minimum possible.

Please note the combination A1 and A4 to Painter 1 with time 50, and A2 and A3 to Painter 2 with time 50, will yield a smaller time (50 units). But this cant be considered due to the constraint that a painter cannot paint non-continuos series of boards.
*/
#include <iostream>
using namespace std;

bool isPossibleBoards(int arr[], int size, int mid, int painters)
{
    int paintersRequired = 1;
    int sumOfBoards = 0;

    for (int i = 0; i < size; i++)
    {
        // if the length of any boards is greater than mid, no painter can be allocated for that thus it is not a possible answer:
        if (arr[i] > mid)
        {
            return false;
        }

        sumOfBoards += arr[i];
        // if sumOfBoards is less than or equal to mid, then keep on adding it to the same painter:
        if (sumOfBoards <= mid)
        {
            continue;
        }
        // else add it to the next painter:
        else
        {
            sumOfBoards = arr[i];
            paintersRequired++;
        }
    }

    // check for the number of PaintersRequired and the painters allowed in the question:
    if (paintersRequired > painters)
    {
        return false;
    }

    return true;
}

int allocateBoards(int arr[], int size, int painters)
{
    // defining the search space for the solutions
    int s = 0;
    int e = 0;
    for (int i = 0; i < size; i++)
    {
        e += arr[i];
    }

    // initilising mid:
    int mid = s + (e - s) / 2;
    int ans;

    while (s <= e)
    {
        // if current mid is a possible answer, then store it and search in the lower half for a more minimum answer:
        if (isPossibleBoards(arr, size, mid, painters))
        {
            ans = mid;
            e = mid - 1;
        }
        // if current mid is not a possible answer, then no number in the lower half will be a possible answer thus search in upper half:
        else
        {
            s = mid + 1;
        }

        // reevaluation mid:
        mid = s + (e - s) / 2;
    }

    return ans;
}

int main()
{
    int arr1[4] = {10, 20, 30, 40};
    int size1 = 4;
    int painters1 = 2;

    int arr2[4] = {5, 5, 5, 5};
    int size2 = 4;
    int painters2 = 2;

    cout << allocateBoards(arr1, size1, painters1) << endl;
    cout << allocateBoards(arr2, size2, painters2) << endl;
}