// given a number , find all the prime numbers less than or equals to this given number
// SEGMENTED SIEVE OF ERATOSTHENES:

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void printVector(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }cout<<endl;
}

// This functions finds all primes smaller than 'limit'
// using simple sieve of eratosthenes. It also stores
// found primes in vector primes[]
void simpleSieve(int x, vector<int> &primes)
{
    vector<bool> v(x, true);

    // traversing the vector upto squareroot(x)
    for (int i = 2; i * i < x; i++)
    {
        if (v[i] == true)
        {
            for (int j = i + i; j < x; j += i)
            {
                v[j] = false;
            }
        }
    }

    // pushing all the prime numbers by traversing the vector v:
    for (int i = 2; i < x; i++)
    {
        if (v[i])
        {
            primes.push_back(i);
        }
    }
}

void segmentedSieve(int n)
{
    //having the range of one segment equal to squareroot of n:
    int limit = sqrt(n) + 1;

    //final answer vector:
    vector<int> primes;

    //finding all primes smaller than 'limit':
    simpleSieve(limit, primes);

    // Divide the range [0..n-1] in different segments:
    int low = limit;
    int high = limit * 2;

    // While all segments of range [0..n-1] are not processed,
    // process one segment at a time:
    while (low < n)
    {
        //if high exceeds n , then set it to n:
        if (high >= n)
        {
            high = n;
        }

        //to mark primes in the current range, create a seperate vector for that range of size limit+1:
        vector<bool> is_primes(limit + 1, true);

        //initialising a for loop on the primes[] vector to get all the numbers that are already present in it:
        for (int i = 0; i < primes.size(); i++)
        {
            // Find the minimum number in [low..high] that is
            // a multiple of primes[i] (divisible by primes[i])
            // For example, if low is 31 and primes[i] is 3,
            // we start with 33:
            int low_limit = floor(low / primes[i]) * primes[i];
            if (low_limit < low)
            {
                low_limit += primes[i];
            }

            //initialising a for loop on the is_primes[] vector to cancel out all the indexes which represent a multiple of primes[i]:
            for (int j = low_limit; j <= high; j += primes[i])
            {
                is_primes[j - low] = false;
            }
        }

        //indexes which are marked as true represent prime, so calculate the relation between indexes and numbers and push the prime numbers to the vector primes[].
        for (int i = low; i <= high; i++)
        {
            if (is_primes[i-low] == true)
            {
                primes.push_back(i );
            }
        }

        // Update low and high for next segment
        low = low + limit;
        high = high + limit;
    }

    printVector(primes);

}//TIME COMPLEXITY: O(sqrt(n)log(log(sqrt(n))))
 //SPACE COMPLEXITY: O(sqrt(n))

int main()
{
    int num = 40;

    segmentedSieve(num);
}