//given a string, reverse it using recursions

#include <iostream>
using namespace std;

void reverse(string & s, int i, int j){
    //base case:
    if(i>j){
        return ;
    }

    swap(s[i],s[j]);
    i++;
    j--;

    //recursive call:
    reverse(s,i,j);
}

int main(){

    string s = "hello";

    reverse(s,0,s.length()-1);

    cout<<s<<endl;

    return 0;
}