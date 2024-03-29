// given a character array, reverse the order of the words
// solve it in-place , i.e. without allocating extra space
//  eg: "the sky is blue" ---> "blue is sky the"

#include <iostream>
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

// function to reverse individual words :
void reverseWords(char arr[])
{
    int i = 0;
    int j = 0;

    while (true)
    {
        // finding the length of current word: (keep on increasing j until reached a space or null character)
        while ((arr[j] != ' ') && (arr[j] != '\0'))
        {
            j++;
        }

        // reversing the current word:
        int start = i;
        int end = j - 1;
        while (start <= end)
        {
            swap(arr[start++], arr[end--]);
        }

        // if reached the end of phrase, i.e. j points to null character, exit the loop:
        if (arr[j] == '\0')
        {
            break;
        }

        // setting i and j to the next word:
        i = j + 1;
        j = j + 1;
    }
}

void reversePhrase(char arr[])
{
    // setting two pointers to start and end of the phrase:
    int s = 0;
    int e = stringLength(arr) - 1;

    // reversing the whole phrase: (will give ---> ".eulb si yks eht")
    while (s <= e)
    {
        swap(arr[s++], arr[e--]);
    }

    // reversing each word seperately of the reversed phrase to get correct words:
    reverseWords(arr);
}

int main()
{
    char arr[100] = "the sky is blue.";

    reversePhrase(arr);

    cout << arr << endl;
}