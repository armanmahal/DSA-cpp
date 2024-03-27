//reversing a vector

#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> vec){
    for(int i = 0; i < vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

vector<int> reverseVector(vector<int> vec){
    int i = 0;
    int j = vec.size() - 1;

    while(i<=j){
        swap(vec[i++], vec[j--]);
    }

    return vec;
}

int main(){
    vector<int> v = {1,2,3,4,5};
    vector<int> v1 = {1,2,3,4,5,6};

    vector<int> reversed_v = reverseVector(v);
    vector<int> reversed_v1 = reverseVector(v1);

    printVector(reversed_v);
    printVector(reversed_v1);
}