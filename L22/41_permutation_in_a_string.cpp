// given two strings 's1' and 's2', consisting of lowercase english letters , return true if s2 contains a permutation of s1.
// eg: s1="ab" s2="eidbaooo" ---> true (as s2 contains 'ba' which is a permutation of s1)

#include <iostream>
#include <string>
using namespace std;

// function to compare two strings of same size:
bool compare(int arr1[], int arr2[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr1[i] != arr2[i])
        {
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2)
{
    // creating an array1 to store the count of characters in s1:
    int array1[26] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        array1[(s1[i] - 'a')]++;
    }

    int windowSize = s1.length();
    // creating an array2 to store the count of charachters in one window of s2:
    int array2[26] = {0};
    int i = 0;
    // checking the characters for first window:
    while (i < windowSize)
    {
        int index = s2[i] - 'a';
        array2[index]++;
        i++;
    }
    // comparing the array of the first window with array1:
    if (compare(array1, array2, 26))
    {
        return true;
    }
    // if not equal then procceed to next windows:
    else
    {
        while (i < s2.length())
        {
            // new character's index will be added to array2:
            char newChar = s2[i];
            array2[(newChar - 'a')]++;

            // old character's index will be deleted from array2:
            char oldChar = s2[i - windowSize];
            array2[(oldChar - 'a')]--;

            // comparing the two arrays at each window:
            if (compare(array1, array2, 26))
            {
                return true;
            }

            // incrementing i:
            i++;
        }

        // if out of loop and substring not found, return false:
        return false;
    }
}

int main()
{
    string s1 = "abid";
    string s2 = "eidbaooo";

    string ans = checkInclusion(s1, s2) ? "true" : "false";

    cout << ans << endl;
}