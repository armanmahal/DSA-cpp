/*
Given that there are N books and M students. Also given are the number of pages in each book in ascending order. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum, with the condition that every student is assigned to read some consecutive books. Print that minimum number of pages.

Example :

Input: N = 4, pages[] = {12, 34, 67, 90}, M = 2
Output: 113

Explanation: There are 2 number of students. Books can be distributed in following combinations:

[12] and [34, 67, 90] -> Max number of pages is allocated to student ‘2’ with 34 + 67 + 90 = 191 pages
[12, 34] and [67, 90] -> Max number of pages is allocated to student ‘2’ with 67 + 90 = 157 pages
[12, 34, 67] and [90] -> Max number of pages is allocated to student ‘1’ with 12 + 34 + 67 = 113 pages
Of the 3 cases, Option 3 has the minimum pages = 113.
*/

#include <iostream>
using namespace std;

bool isValidPages(int arr[], int size, int mid, int students)
{
    int studentsRequired = 1;
    int sumOfPages = 0;

    for (int i = 0; i < size; i++)
    {
        // if mid is less than the number of pages of any one book, it is not valid:
        if (arr[i] > mid)
        {
            return false;
        }

        sumOfPages = sumOfPages + arr[i];
        // if sum of pages does not exceed mid, keep on adding the pages to that one student:
        if (sumOfPages <= mid)
        {
            continue;
        }
        // if sum of pages exceeds the mid, allot the next book to next student, hence increasing the number of students:
        else
        {
            sumOfPages = arr[i];
            studentsRequired++;
        }
    }
    // if student required to allot all the books is more than the given number of students than , it is not a valid solution
    if (studentsRequired > students)
    {
        return false;
    }
    // else it is a possible solution
    return true;
}

int allocateBooks(int arr[], int size, int students)
{
    // defining the search space:
    int s = 0;
    int e = 0;
    // e is equal to sum of all pages of all books
    for (int i = 0; i < size; i++)
    {
        e += arr[i];
    }

    // initialising mid:
    int mid = s + (e - s) / 2;

    int ans = -1;

    // condition:
    while (s <= e)
    {
        // if the current pages are a valid solution, store it and continue your search in lower half:
        if (isValidPages(arr, size, mid, students))
        {
            ans = mid;
            e = mid - 1;
        }
        // if the current pages is not a valid solution, then any number of pages below this will also not be a valid solution, so search in upper half:
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

    int arr[4] = {12, 34, 67, 90};
    int m = 2; // students
    int n = 4; // no. of books

    cout << allocateBooks(arr, n, m) << endl;
}
