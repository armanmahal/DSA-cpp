// given a phrase check if it is a palindrome or not after removing all whitespaces
// and special characters , it is not case sensitive
// eg: "A man, a plan, a canal: Panama." ---> "amanaplanacanalpanama" ---> it is a palindrome

#include <iostream>
#include <string>
using namespace std;

// function to always return lower case of any character
char toLowerCase(char ch)
{
    // if character is already lower case just return it
    if (ch >= 'a' && ch <= 'z')
    {
        return ch;
    }
    return (ch + ('a' - 'A')); // to convert upper case to lower case just add 32 to it or add ('a' - 'A')
                               // because the difference between upper case and lower case character in ascii table is 32
}

// function to remove uncessary characters
string removeUneccesary(string s)
{
    // creating a temp string to store the answer string:
    string temp;

    // looping the string s
    for (int i = 0; i < s.size(); i++)
    {
        // if s[i] is a valid character, add its lowercase form to 'temp':
        if (('0' <= s[i] && s[i] <= '9') || ('A' <= s[i] && s[i] <= 'Z') || ('a' <= s[i] && s[i] <= 'z'))
        {
            temp.push_back(toLowerCase(s[i]));
        }
    }

    return temp;
}

// function to check palindrome
void checkPalindrome(string s)
{
    int i = 0;
    int j = s.size() - 1;

    bool palindrome = true;

    while (i <= j)
    {
        // if any character doesnt match, palindrome becomes false:
        if (s[i] != s[j])
        {
            palindrome = false;
            break;
        }
        i++;
        j--;
    }

    if (palindrome)
    {
        cout << "It is a Palindrome" << endl;
    }
    else
    {
        cout << "not a palindrome" << endl;
    }
}

int main()
{
    string s = "A man, a plan, a canal: Panama.";

    s = removeUneccesary(s);

    cout << s << endl;

    checkPalindrome(s);
}