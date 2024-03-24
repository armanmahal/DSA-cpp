//to find sum and product of all the digits in a number

#include <iostream>
using namespace std;

int main(){

    int sum = 0;
    int product = 1;

    int number;
    cout<<"enter the number: ";
    cin>>number;

    while (number!=0){

        //to last digit of the number as remainder operator is used:
        int digit = number % 10 ; 

        sum = sum + digit;
        product = product * digit;

        // this will remove the last digit from the number:
        number = number / 10 ; 
    }

    cout<<"The sum is: " << sum << endl << "The product is: " << product << endl;

    return 0;
}