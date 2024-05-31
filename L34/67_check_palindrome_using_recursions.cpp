// checking palindrome using recursions

#include <iostream>
using namespace std;

bool isPalindrome(string s, int i, int j)
{
    // base case:
    if (i > j)
    {
        return true;
    }

    // checking palindrome:
    if (s[i] != s[j])
    {
        return false;
    }
    // recursive call:
    else
    {
        return isPalindrome(s, ++i, --j);
    }
}

int main()
{

    string s = "aabbaa";
    string s1 = "KaababaaK";
    string s2 = "aaabbaa";

    cout << isPalindrome(s, 0, s.length() - 1) << endl;
    cout << isPalindrome(s1, 0, s1.length() - 1) << endl;
    cout << isPalindrome(s2, 0, s2.length() - 1) << endl;
}