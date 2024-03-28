// given a character array, reverse each of its words:
// eg : "The sky is Blue" ---> "ehT yks si eulB"
//  SOLVE THE QUESTION IN-PLACE , i.e. without using any extra space , i.e. space complexity - O(1).

#include <iostream>
using namespace std;

void reverseWords(char arr[])
{
    int i = 0;
    int j = 0;

    while (true)
    {
        while ( (arr[j] != ' ') && (arr[j] != '\0') )
        {
            j++;
        }

        int start = i;
        int end = j - 1;
        while (start <= end)
        {
            swap(arr[start++], arr[end--]);
        }

        if (arr[j] == '\0')
        {
            break;
        }

        i = j + 1;
        j = j + 1;
    }
}

int main()
{
    char arr[100] = "The sky is Blue";

    reverseWords(arr);

    cout << arr << endl;
}