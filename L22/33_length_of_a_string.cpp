//to find length of a string (char array)

#include <iostream>
#include <string>
using namespace std;

int stringLength(char arr[]){
    int length = 0;
    int i = 0;
    //keep on increasing length until null character'\0' is reached:
    while(arr[i]!='\0'){
        length++;
        i++;
    }

    return length;
}

int main(){
    char name[] = "abc abcc";
    char greeting[100] = "hello sir";
    
    cout<<stringLength(name)<<endl;
    cout<<stringLength(greeting)<<endl;
}