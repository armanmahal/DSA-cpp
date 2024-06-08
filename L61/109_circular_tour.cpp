// Find the first circular tour that visits all petrol pumps

/*
Given information about N petrol pumps (say arr[]) that are present in a circular path. The information consists of the distance of the next petrol pump from the current one (in arr[i][1]) and the amount of petrol stored in that petrol pump (in arr[i][0]). Consider a truck with infinite capacity that consumes 1 unit of petrol to travel 1 unit distance. The task is to find the index of the first starting point such that the truck can visit all the petrol pumps and come back to that starting point.

Note: Return -1 if no such tour exists.
*/

// Examples:
/*
Input: arr[] = {{4, 6}, {6, 5}, {7, 3}, {4, 5}}.
Output: 1
Explanation: If started from 1st index then a circular tour can be covered.

Input: arr[] {{6, 4}, {3, 6}, {7, 3}}
Output: 2
*/

#include <iostream>
using namespace std;

// BRUTEFORCE APPROACH-> O(n^2): A Simple Solution is to consider every petrol pumps as a starting point and see if there is a possible tour. If we find a starting point with a feasible solution, we return that starting point:
void solve(int arr[][2], int pumps)
{
    bool indexFound = false;

    // for loop to check each index as the start index:
    for (int i = 0; i < pumps; i++)
    {
        int currentPetrol = arr[i][0];
        int nextDistance = arr[i][1];

        if (currentPetrol < nextDistance)
        {
            continue;
        }

        for (int j = (i + 1); j < (i + pumps); j++)
        {
            int current = j % pumps;

            currentPetrol = currentPetrol - nextDistance + arr[current][0];
            nextDistance = arr[current][1];
            if (currentPetrol < nextDistance)
            {
                break;
            }
            else if ((current == pumps - 1 && i == 0) || (current == i - 1))
            {
                indexFound = true;
                cout << "The index is :" << i << endl;
            }
        }
        if (indexFound)
        {
            return;
        }
    }
    if (!indexFound)
    {
        cout << "No index Found" << endl;
    }
}

// APPROACH 2 -> O(n) :
void solve2(int arr[][2], int pumps)
{
    int deficitPetrol = 0;
    int balancePetrol = 0;
    int start = 0;

    for (int i = 0; i < pumps; i++)
    {
        balancePetrol = balancePetrol + (arr[i][0] - arr[i][1]); // petrol - distance
        if (balancePetrol < 0)
        {
            deficitPetrol = deficitPetrol + balancePetrol;
            // increasing the start index:
            start = i + 1;
            balancePetrol = 0;
        }
    }

    if (deficitPetrol + balancePetrol >= 0)
    {
        // then path is possible from current start:
        cout << "The index is :" << start << endl;
    }
    else
    {
        cout << "No index Found" << endl;
    }
}

int main()
{

    // 0 index of each subarray gives amount of petrol stored in pump.
    // 1 index of each subarray gives distance of next petrol pump.
    // i.e.: {petrol, distance}

    int arr1[4][2] = {{4, 6}, {6, 5}, {7, 3}, {4, 5}};
    solve(arr1, 4);
    solve2(arr1, 4);

    int arr2[3][2] = {{6, 4}, {3, 6}, {7, 3}};
    solve(arr2, 3);
    solve2(arr2, 3);

    int arr3[5][2] = {
        {10, 20},
        {20, 30},
        {15, 25},
        {25, 15},
        {30, 10}};
    solve(arr3, 5);
    solve2(arr3, 5);
}