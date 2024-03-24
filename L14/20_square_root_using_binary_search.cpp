//given an integer n , find its square root without decimal part

#include <iostream>
using namespace std;

long long int squareRoot(int n){
    //initializing two pointers for start and end of search space
    int s = 0;
    int e = n;

    //long long int is necessary or the code will break on multiplying if mid is a big value
    long long int ans = -1;
    long long int mid = s + (e-s)/2 ;

    //condition:
    while(s<=e){
        long long int square = mid*mid;
        //if midxmid == n we get the answer
        if(square == n){
            return mid;
        }
        //if midxmid is larger than the number, search in lower half:
        else if(square > n){
            e = mid - 1;
        }
        //if midxmid is smaller than number, store the mid in ans and search in upper half
        else{
            ans = mid;
            s = mid + 1;
        }
        //updating mid:
        mid = s + (e-s)/2;
    }

    return ans;
}

int main(){
    int n =  117529;

    cout<<squareRoot(n)<<endl;
}