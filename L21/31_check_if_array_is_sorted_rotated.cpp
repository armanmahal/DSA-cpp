//given an array check if it is sorted and rotated
//eg: {4,5,1,2,3} ---> true

#include <iostream>
using namespace std;

void checkSortedRotated(int arr[], int size){

    int counter = 0;

    for(int i = 0; i< size-1; i++){

        if(arr[i+1] < arr[i]){
            counter++;
        }
 
    }

    if(arr[0] < arr[size-1]){
        counter++;
    }

    if(counter<=1){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }

}

int main(){
    int arr[5] = {3,4,5,1,2};
    int arr2[5] = {1,2,3,4,5};
    int arr3[5] = {1,2,9,4,5};

    checkSortedRotated(arr, 5);
    checkSortedRotated(arr2, 5);
    checkSortedRotated(arr3, 5);
}