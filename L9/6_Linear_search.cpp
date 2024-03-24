// implement Linear search to find a element(key) from an array.

#include <iostream>
using namespace std;

//defining the Function to linearly search the element:
bool linearSearch ( int arr[], int size , int key){

    //traversing the array:
    for(int i = 0 ; i < size ; i++){

        //check the condition:
        if(arr[i]==key){
            return true;
        }
    }

    //return false if condition on met on traversing:
    return false;

}

int main (){

    int arr[10] = {2,32,0,1,23,4,34,0,7,4};

    int key = 34;

    //passing array to linearSearch function
    bool findElement = linearSearch(arr, 10 , key);

    //printing the result
    if(findElement){
        cout<<"The key is present"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }
}