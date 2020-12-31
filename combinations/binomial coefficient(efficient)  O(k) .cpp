#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull binomial_coefficient(ull n, ull k)
{
    ull ans=1;
    if(k>n-k)
        k=n-k;

    for(ull i=0; i<k; i++)
    {
        ans=ans*(n-i);
        ans=ans/(i+1);
    }

    return ans;
}

int main()
{
    ull n,k;
    while(cin>>n>>k)
    cout<<binomial_coefficient(n,k)<<endl;
}

