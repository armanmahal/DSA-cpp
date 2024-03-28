// given a string , check if it is a palindrome or not, it is not case sensitive,
//  and ignore all the special characters and whitespaces
//  eg: "c1 O$d@eeD o1c" ---> "c1odeedo1c" ---> it is a palindrome

#include <iostream>
#include <string>
using namespace std;

//function to always return lower case of any character
char toLowerCase(char ch)
{
    //if character is already lower case just return it
    if (ch >= 'a' && ch <= 'z')
    {
        return ch;
    }
    return (ch + ('a' - 'A')); // to convert upper case to lower case just add 32 to it or add ('a' - 'A') 
                               // because the difference between upper case and lower case character in ascii table is 32
}

bool checkPalindrome(string s)
{
    //initialising two pointers for start and end of string to compare the start and end:
    int i = 0;
    int j = s.size() - 1;

    while (i <= j)
    {
        //if s[i] is not a valid character between 0-9 or a-z or A-Z:
        if (!(('0' <= s[i] && s[i] <= '9') || ('A' <= s[i] && s[i] <= 'Z') || ('a' <= s[i] && s[i] <= 'z')))
        {
            i++;
            continue;
        }
        //if s[j] is not a valid character between 0-9 or a-z or A-Z:
        if (!(('0' <= s[j] && s[j] <= '9') || ('A' <= s[j] && s[j] <= 'Z') || ('a' <= s[j] && s[j] <= 'z')))
        {
            j--;
            continue;
        }
        //returning false whenever on comparing the characters dont match:
        if (toLowerCase(s[i]) != toLowerCase(s[j]))
        {
            return false;
        }
        //changing the pointers if both characters are matched:
        else
        {
            i++;
            j--;
        }
    }
    // returning true if successfully compared all the characters:
    return true;
}

int main()
{
    string s = "c1 O$d@eeD o1c";

    if (checkPalindrome(s))
    {
        cout << "it is a palindrome" << endl;
    }
    else
    {
        cout << "not a palindrome" << endl;
    }
}