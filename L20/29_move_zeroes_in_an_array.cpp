//given an array, move all its zeroes to the end , while maintaining the relative order of rest of the elements
//eg: {0,1,0,3,12,0} ---> {1,3,12,0,0,0}
#include <iostream>
using namespace std;

void printArray(int arr[], int size){
    for(int i = 0 ; i < size; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

void moveZeroes(int arr[], int size){
    //pointer which will always be pointing to the leftmost index which has element zero to it:
    int lastZeroIndex = 0;

    int j = 0;

    while(j<size){
        //if arr[j] is non zero than swap it with the last index which is zero and increment the lastZeroIndex:
        if(arr[j] != 0){
            swap(arr[j] , arr[lastZeroIndex]);
            lastZeroIndex++;
        }

        //incrementing j to continue the loop on next iteration
        j++;

    }
}

int main(){

    int arr[8] = {0,1,0,0,0,3,12,0};

    printArray(arr, 8);

    moveZeroes(arr, 8);

    printArray(arr, 8);

}