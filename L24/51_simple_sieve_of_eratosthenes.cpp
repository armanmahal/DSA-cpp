// given a number , find all the prime numbers less than or equals to this given number
// SIMPLE SIEVE OF ERATOSTHENES:

#include <iostream>
#include <vector>
using namespace std;

void simpleSieve(int x)
{

    // create a vector of size 'x+1' because we have to include the given number also in the vector indexes and initialize all its values with true, true index represent that it a prime number and false will represent that it is not a prime number:
    vector<bool> v(x+1, true);

    //initializing the count of number of primes:
    int count = 0;

    //traversing the vector upto squareroot(x+1)
    for (int i = 2; i*i < x+1; i++)
    {
        //if the current index of vector is true, then it means there is a prime number at that index, then initialize a for loop to change the values of multiples of current index to false as they become divisible by current index:
        if (v[i] == true)
        {
            for (int j = i+i ; j < x+1 ; j += i)
            {
                v[j] = false;
            }
        }
    }

    //printing all the prime numbers by traversing the vector v:
    for( int i = 2; i < x+1; i++ ){
        if(v[i]){
            cout<<i<<" ";
            count++;
        }
    }cout<<endl;

    cout << "Number Of Primes : " << count << endl;
}//TIME COMPLEXITY: O(n*log(log(n)))
 //SPACE COMPLEXITY: O(n)

int main()
{
    int num = 101;

    simpleSieve(num);
}