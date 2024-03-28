//you are given two arrays whose elements represent a digit,
//find the sum of these two digits with arrays
//eg: {9,1,8,3} + {9,3,2} ---> {1,0,1,1,5}

#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v){
    for(int i = 0; i< v.size(); i++){
        cout<<v[i]<<' ';
    }cout<<endl;
}

void reverseVector(vector<int> & v){
    int i = 0;
    int j = v.size()-1;

    while(i<=j){
        swap(v[i++], v[j--]);
    }
}

vector<int> addArray(vector<int> arr1, vector<int> arr2){
    //intialising two pointers to the end of each array because addition starts from the element of least significance:
    int i = arr1.size()-1;
    int j = arr2.size()-1;

    vector<int> ans;

    //initialising carry as zero:
    int carry = 0;

    //loop to traverse the whole integer until one of the ends:
    while(i>=0 && j>=0){
        int sum = carry + arr1[i] + arr2[j];

        carry = sum/10;

        sum = sum%10;

        ans.push_back(sum);

        i--;j--;
    }
    //if arr1 is larger than arr2, then to complete addition:
    while(i>=0){
        int sum = carry + arr1[i];

        carry = sum/10;

        sum = sum%10;

        ans.push_back(sum);

        i--;
    }
    //if arr2 is larger than arr1, then to complete addition:
    while(j>=0){
        int sum = carry + arr2[j];

        carry = sum/10;

        sum = sum%10;

        ans.push_back(sum);

        j--;
    }
    //if there remains an extra carry at the end of calculations:
    if(carry==1){
        ans.push_back(1);
    }

//reversing the vector ans to get the answer in correct order:
    reverseVector(ans);

    return ans;
}

int main(){

    vector<int> arr1 = {9,1,8,3} ;
    vector<int> arr2 = {9,3,2};

    vector<int> addition = addArray(arr1,arr2);

    printVector(arr1);
    cout<<"+"<<endl;
    printVector(arr2);
    cout<<"="<<endl;
    printVector(addition);

}