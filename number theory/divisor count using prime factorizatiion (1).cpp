#include<bits/stdc++.h>

using namespace std;
vector<int>primes;
int countDivisor(int n)
{
    int z=   primes.size()/2;
    int divisor = 1;
    for (int i = 0; i < z; i++)
    {
        if (n % primes[i] == 0)
        {
            int cnt = 1;
            while (n % primes[i] == 0)
            {
                n /= primes[i];
                cnt++;
            }
            divisor *= cnt;
        }
    }
    return divisor;
}
int main()
{
    cout<<"Enter the number to find it's divisor:"<<endl;
    size_t n ;
    cin >> n ;
    vector<bool> sieve( n, true ) ;
    int ub =  sqrt(n) + 1.5 ;
    for( int i = 2 ; i < ub ; ++i )
        if( sieve[i] == true )
        {
            for(  size_t j = i*i ; j<n ; j += i )
                sieve[j] = false ;
        }

    for(  size_t i = 2 ; i < n ; ++i )
        if( sieve[i] == true )
        {
            primes.push_back(i);
        }


    cout<<"Divisor :"<<countDivisor(n)<<endl;
    return 0;
}

