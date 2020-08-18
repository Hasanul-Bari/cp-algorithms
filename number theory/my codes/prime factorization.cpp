#include<bits/stdc++.h>
using namespace std;

vector<long long> primes;

void primefactorize(long long n)
{
    for(long long i=0; i<=(primes.size()/2); i++)
    {
        if(n%primes[i]==0)
        {
            while(n%primes[i]==0)
            {
                cout<<primes[i]<<" ";
                n=n/primes[i];
            }
        }
    }
}


void seiveoferatosthenis(long long n)
{
    vector<bool> prime(n,true);

    for(long long i=2; i*i<=n; i++)
    {
        if(prime[i]==true)
        {
            for(int j=i*i; j<=n; j=j+i)
                prime[j]=false;
        }
    }

    for(long long i=2; i<=n; i++)
    {
        if(prime[i]==true)
            primes.push_back(i);
    }


}


int main()
{
    long long n;
    cin>>n;

    for(int i=0 ; i<n; i++)
    {
        seiveoferatosthenis(i);
        primefactorize(i);
    }


    return 0;

}
