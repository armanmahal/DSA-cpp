/*
given an array of characters consisting of repeating lowercase alphabets, compress it using the following algorithm:
 -> if there exists a repeating character , append it to the array followed by it frequency,
 -> if there exists a non repeating character, append it to the array and dont write its frequency

 eg: "aabbbcdddd" ---> "a2b3cd4"

 USE ONLY CONSTANT SPACE, i.e. SOLVE IT IN-PLACE.
*/
#include <iostream>
#include <string>
using namespace std;

int stringLength(char arr[])
{
    int length = 0;
    int i = 0;
    while (arr[i] != '\0')
    {
        length++;
        i++;
    }
    return length;
}

void compressString(char arr[], int length)
{
    int lastIndex = 0;
    // setting the current character and its count as one:
    char currentChar = arr[0];
    int currentCount = 1;

    // iterating the string:
    for (int i = 1; i < length; i++)
    {
        // if character of current iteration is equal to the current character whose count we are counting, then increase its count:
        if (arr[i] == currentChar)
        {
            currentCount++;
        }

        // if character of current iteration is changed from the current character whose count we are counting:
        else
        {
            // if count of character was one:
            if (currentCount == 1)
            {
                arr[lastIndex] = currentChar;
                lastIndex++;

                // resetting current character:
                currentChar = arr[i];
            }
            // if count of character was more than one:
            else
            {
                arr[lastIndex] = currentChar;
                lastIndex++;

                // converting its count from int to string:
                string currentCountString = to_string(currentCount);
                // writing current count into the array:
                for (char ch : currentCountString)
                {
                    arr[lastIndex] = ch;
                    lastIndex++;
                }

                // resetting current character and its count:
                currentChar = arr[i];
                currentCount = 1;
            }
        }
    }

    // the loop will end on the last index without adding it to the array, so add the count of last character manually:
    arr[lastIndex] = currentChar;
    lastIndex++;

    string currentCountString = to_string(currentCount);
    for (char ch : currentCountString)
    {
        arr[lastIndex] = ch;
        lastIndex++;
    }

    // cutting off the rest of the array:
    arr[lastIndex] = '\0';
}

int main()
{

    char arr[100] = "aaabbcdddddd";
    int length = stringLength(arr);

    compressString(arr, length);

    cout << arr << endl;
}
