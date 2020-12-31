#include<bits/stdc++.h>
using namespace std;

long long binomial_coefficient(long long n, long long k)
{
    if(k==0 || k==n)
        return 1;

    return binomial_coefficient(n-1,k-1)+binomial_coefficient(n-1,k);
}

int main()
{
    long long n,k;
    cin>>n>>k;
    cout<<binomial_coefficient(n,k)<<endl;
}
