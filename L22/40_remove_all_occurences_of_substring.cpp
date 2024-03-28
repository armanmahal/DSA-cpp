//given two strings 's' and 'part'  , find the leftmost substring 'part' and remove it from 's' , until there is no 'part' left.
//eg: s= "daabcbaabcbc" , part = "abc" ::: "daabcbaabcbc" ---> "dabaabcbc" ---> "dababc" ---> "dab"

#include <iostream>
#include <string>
using namespace std;

string removeOccurences(string s , string part){

    // s.find(part) will give the leftmost index of 'part'.
    //eg: if s = "abccab" , s.find("cab") will give 3. s.find("b") will give 1.

    // s.erase({index from which erasing should start},{number of elements that need to be erased})

    // if s.find(part) exceeds the s.length() , then we can imply that 'part' does not exits in 's'.

    while((s.length()!=0) && (s.find(part) < s.length() )){
            s.erase(s.find(part) , part.length());
    }

    return s;
}

int main(){
    string s = "daabcbaabcbc";
    string part = "abc";

    string s_changed = removeOccurences(s,part);

    cout<<s_changed<<endl;
}