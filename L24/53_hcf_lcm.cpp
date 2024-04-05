//find hcf and lcm of two numbers:

#include <iostream>
using namespace std;

// Function to find HCF using Euclidean algorithm
int findHcf(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find LCM using HCF
int findLcm(int a, int b) {
    int hcf = findHcf(a, b);
    int lcm = (a * b) / hcf;
    return lcm;
}

int main(){

    int num1, num2;

    cout<<"Enter the first number: ";
    cin>>num1;
    cout<<"Enter the second number: ";
    cin>>num2;

    int hcf = findHcf(num1,num2);
    int lcm = findLcm(num1,num2);

    cout<<"HCF is: "<<hcf<<", LCM is: "<<lcm<<endl;

}