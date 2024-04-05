//to check whether a given number is prime or not

#include <iostream>
using namespace std;

bool isPrime(int n) {
    //if number is less than or equal zero return false
    if (n <= 1) {
        return false;
    }
    //check the divisibly of all integers from [2,squareroot(n)]
    for (int i = 2; (i*i) <= n ; i++) {
        //if divisible , it is not a prime:
        if (n % i == 0) {
            return false;
        }
    }
    //if not divisible by any, it is a prime:
    return true;
}//TIME COMPLEXITY: O(n)

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if (isPrime(num)) {
        cout << num << " is a prime number.\n";
    } else {
        cout << num << " is not a prime number.\n";
    }
    return 0;
}