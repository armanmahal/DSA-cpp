/*
given two sorted arrays , merge them into one array ,
the merged array should also be sorted
{1,3,6} + {1,2,3,4,5,7} ---> {1,1,2,3,3,4,5,6,7}
*/
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> vec){
    for(int i = 0; i < vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

vector<int> mergeArrays(int arr1[], int size1, int arr2[], int size2){
    //initialising two pointers for the two arrays
    int i = 0;
    int j = 0;

    vector<int> ans;

    //loop until both the pointers are within the size of both of the respective arrays:
    while(i < size1 && j < size2){
        //if current elements of both arrays are equal:
        if(arr1[i] == arr2[j]){
            ans.push_back(arr1[i]);
            ans.push_back(arr2[j]);
            i++;
            j++;
        }
        //if current element of array1 is smaller than array2
        else if(arr1[i] < arr2[j]){
            ans.push_back(arr1[i]);
            i++;
        }
        //if current element of array2 is smaller than array1
        else{
            ans.push_back(arr2[j]);
            j++;
        }
    }

    //loop until all the elements of arr1 are iterated (in case arr1 is larger in size than arr2) :
    while(i<size1){
        ans.push_back(arr1[i]);
        i++;
    }

     //loop until all the elements of arr2 are iterated (in case arr2 is larger in size than arr1) :
    while(j<size2){
        ans.push_back(arr2[j]);
        j++;
    }

    return ans;
}

int main(){
    int arr1[3] = {1,3,6};
    int arr2[6] = {1,2,3,4,5,7};

    vector<int> arr3 = mergeArrays(arr1, 3, arr2, 6);

    printVector(arr3);
}
