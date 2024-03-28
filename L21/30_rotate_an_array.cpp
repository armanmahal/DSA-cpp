//given an array, rotate it by 'k' steps
//eg {1,2,3,4,5} , k = 2 ---> {4,5,1,2,3}

#include <iostream>
using namespace std;

void printArray(int arr[], int size){
    for(int i = 0 ; i < size; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

void rotateArray(int arr[], int size, int k){
    //creating a new array to store rotate elements:
    int rotated_arr[5];

    //traversing the original array:
    for(int i = 0; i< size; i++){
        //index this element is to be placed at:
        int index = (i+k)%size;
        //positioning this arr[i] element in rotated array:
        rotated_arr[index] = arr[i];
    }
        
    printArray(rotated_arr, size);    
    
}

int main(){
    int arr[5] = {1,2,3,4,5};
    int k = 2;

    rotateArray(arr, 5,  k);
}