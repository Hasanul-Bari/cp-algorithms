#include<bits/stdc++.h>
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define pb push_back
const double PI = acos(-1.0);
using namespace std;

void primefactorize(ll n)
{
    for(ll i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                cout<<i<<" ";
                n=n/i;
            }
        }
    }
    if(n>1)
        cout<<n<<" ";



}

int main()
{
    ll n;
    cin>>n;

    //for(ll i=1; i<=n; i++)
    {
         //cout<<i<<" -> ";
         primefactorize(n);
         cout<<endl;
    }
    return 0;
}
