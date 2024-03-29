// given a string, consisting of only lowercase english alphabets,
// remove all the adjacent duplicates from the string.
// eg: "abbaca" --> "aaca" --> "ca"
// eg: "azxxzy" --> "azzy" --> "ay"

#include <iostream>
#include <string>
using namespace std;

string removeDuplicates(string s)
{
    int duplicatesExist = true;

    // traversing the string until there's chance of some duplicate existing:
    while (duplicatesExist)
    {

        // if there is no equal elements duplicatesExist will remain false and the loop will break:
        duplicatesExist = false;

        // traversing the string:
        for (int i = 1; i < s.length(); i++)
        {
            //if duplicates found:
            if (s[i - 1] == s[i])
            {
                //s.erase( {the index from which erasing should start} , {the amount of characters that should be erased after index} )
                s.erase( (i - 1) , 2);
                duplicatesExist = true;
                break;
            }
        }
    }

    return s;
}

int main()
{
    string s1 = "abbaca";
    string s2 = "azxxzy";
    string s3 = "azxxzay";
    string s4 = "azxxzayyyyx";

    cout << removeDuplicates(s1) << endl;
    cout << removeDuplicates(s2) << endl;
    cout << removeDuplicates(s3) << endl;
    cout << removeDuplicates(s4) << endl;
}