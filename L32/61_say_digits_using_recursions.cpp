// given an integer '453' , print its name "Four Five Three"

#include <iostream>
using namespace std;

void sayDigits(int n, string *arr)
{
    // Base Case:
    if (n == 0)
    {
        return;
    }

    // recursive call:
    sayDigits(n / 10, arr);

    // printing the current digits name
    int digit = n % 10;
    cout << arr[digit] << " ";
}

int main()
{
    string arr[10] = {"Zero",
                      "One",
                      "Two",
                      "Three",
                      "Four",
                      "Five",
                      "Six",
                      "Seven",
                      "Eight",
                      "Nine"};

    int num = 453;
    cout << endl;
    sayDigits(num, arr);
    cout << endl;
}