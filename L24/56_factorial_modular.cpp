// given a large integer find its factorial modulo m , where m is given,
//  for eg: given x = 100 and m = (10^9)+7 , find: (x!)%m => (100!)%((10^9)+7)

#include <iostream>
using namespace std;

long long int modularFactorial(int x, int m)
{
    long long int ans = 1;

    for (int i = 1; i <= x; i++)
    {
        // as (ans*i)%m => ((ans%m)*(i%m))%m
        ans = ((ans % m) * (i % m)) % m;
    }

    return ans;
}

int main()
{

    int x = 100;
    int m = 1000000007;

    long long int ans = modularFactorial(x, m);

    cout << ans << endl;
}