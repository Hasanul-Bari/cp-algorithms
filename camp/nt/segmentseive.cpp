#include<bits/stdc++.h>
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define pb push_back
const double PI = acos(-1.0);
using namespace std;


vector<ll> primes;


void seive(ll n)
{
    vector<bool> flag(n,true);

    for(ll i=2; i*i<=n; i++)
    {
        if(flag[i]==true)
        {
            for(ll j=i*i; j<=n; j=j+i)
                flag[j]=false;
        }
    }

    for(ll i=2; i<=n; i++)
    {
        if(flag[i]==true)
            primes.pb(i);
    }
}

void segmentSeive(ll l,ll r)
{
    vector<bool> isPrime(r-l+1,true);

    if(l==1)
        isPrime[0]=false;

    for(ll i=0 ; primes[i]*primes[i]<=r ; i++)
    {
        ll curPrime=primes[i];
        ll base=curPrime*curPrime;
        if(base<l)
        {
            base=((l+curPrime-1)/curPrime)*curPrime;
        }

        for(ll j=base ; j<=r ; j=j+curPrime)
            isPrime[j-l]=false;
    }
    for(int i=0 ; i<=r-l ; i++)
    {
        if(isPrime[i]==true)
            cout<<l+i<<endl;
    }
    cout<<endl;
}



int main()
{
    faster



    seive(10000);  ///sqrt(n)

    ll l,r;
    cin>>l>>r;

    segmentSeive(l,r);





    return 0;
}
