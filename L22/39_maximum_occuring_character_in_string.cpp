// given an string, print the character which occurs the maximum number of times, not case sensitive.
// eg: "HelloWorld" ---> 'l'

#include <iostream>
#include <string>
using namespace std;

void maxOccurence(string s)
{

    int i = 0;

    // initialising an array of 26 length with zero, where each index represent a letter of english alphabet{eg: arr[0]-->'a',arr[1]-->'b'...so on}:
    int array[26] = {0};

    int temp = 0;
    while (temp < s.length())
    {
        // index which represent current element:
        int index;

        int currentChar = s[temp];

        // if lowercase letter its index is:
        if ('a' <= currentChar && currentChar <= 'z')
        {
            index = currentChar - 'a';
        }
        // if upperCase letter its index is:
        else if ('A' <= currentChar && currentChar <= 'Z')
        {
            index = currentChar - 'A';
        }
        // if not an English letter than continue to next character:
        else
        {
            temp++;
            continue;
        }
        // increment the index of current letter:
        array[index]++;

        temp++;
    }

    // iterating the the array to find the greatest index:
    int maxValue = -1;
    int maxIndex = 0;
    for (int i = 0; i < 26; i++)
    {
        if (array[i] > maxValue)
        {
            maxValue = array[i];
            maxIndex = i;
        }
    }

    // printing the letter which corresponds to max Index:
    char answer = 'a' + maxIndex;
    cout << answer << endl;
}

int main()
{
    string s = "Hello World zzzz";

    maxOccurence(s);
}