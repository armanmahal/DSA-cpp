// to reverse a string

#include <iostream>
#include <string>
using namespace std;

int stringLength(char arr[])
{
    int length = 0;
    int i = 0;
    // keep on increasing length until null character'\0' is reached:
    while (arr[i] != '\0')
    {
        length++;
        i++;
    }

    return length;
}

void reverseString(char arr[], int size)
{
    int s = 0;
    int e = size - 1;

    while (s < e)
    {
        swap(arr[s++], arr[e--]);
    }
}

int main()
{
    char arr[] = "hello";
    int size = stringLength(arr);

    reverseString(arr, size);

    cout << arr << endl;
}