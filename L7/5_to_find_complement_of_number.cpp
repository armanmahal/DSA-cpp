//complement of an integer is the integer that you get after 
//flipping all the bits of the former integer in binary representation.
// example : 5 = 101 ---> 010 = 2
// example : 7 = 111 ---> 000 = 0

#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the Integer :";
    cin>>n;

    //edge case:
    if(n==0){
        cout<<"1"<<endl;
        return 0;
    }

    int temp = n;
    int mask = 0;

    //creating a mask:
    while (temp!=0){
        temp = temp >> 1;
        mask = (mask << 1) | (1);
    }

    // formula to find the answer:
    int answer = (~n) & (mask);

    cout<<answer<<endl;
    return 0;
}