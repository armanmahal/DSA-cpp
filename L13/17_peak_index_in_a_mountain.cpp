//given an array of the following type:
// {0,3,4,5,10,2,3,1} , its element first increases then decreases,
// find the index of peak element.
#include <iostream>
using namespace std;

int findPeak(int arr[], int size){
    //initializing two pointers for start and end:
    int s = 0;
    int e = size-1;

    //initializing mid:
    int mid = s + (e-s)/2;

    //condition:
    while (s<e)
    {   
        //if mid lies on ascent of mountain:
        if(arr[mid]<arr[mid+1]){
            s = mid+1;
        }
        //if mid lies on descent of mountain 'or' mid IS THE PEAK of mountain:
        else{
            e = mid;
        }

        //updating mid:
        mid = s + (e-s)/2;
    }
    
    //after the loop is complete the 's' and 'e' both will 
    //be pointing to the index of the peak, thus:

    return e;
}

int main(){
    int arr[8] = {0,3,4,5,10,3,2,1};

    cout<<"Peak Index is: "<<findPeak(arr,8)<<endl;
}