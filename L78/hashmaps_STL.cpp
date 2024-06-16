// hashmaps in stl

#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{

    // CREATION :
    unordered_map<char, int> m;

    // INSERTION:

    // 1st way:
    pair<char, int> p = make_pair('a', 3);
    m.insert(p);

    // 2nd way:
    m['b'] = 4;
    m['c'] = 6;

    // SEARCHING:

    // 1st way:
    // this will create a new entry with this key if it does not exist (with its value as 0)
    cout << m['b'] << endl;
    cout << m['d'] << endl; // 'd' did not exist before this.

    // 2nd way:
    // this will not create a new entry if its does not exist .
    cout << m.at('b') << endl;
    /*cout << m.at('f') << endl;*/ // this will throw an error as it does not exist

    // ITERATING:
    for (auto i : m)
    {
        // i will be a key-value pair.
        cout << i.first << " " << i.second << endl;
    }
}