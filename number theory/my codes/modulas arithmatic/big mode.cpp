#include<bits/stdc++.h>
using namespace std;

long long bigmod(long long a,long long b, long long m )
{
    long long x;

    if(b==0)
        return 1;

    x=bigmod(a,b/2,m);
    x=(x*x)%m;

    if(b%2!=0)
        x=(x*a)%m;
    //cout<<a<<" "<<b<<" "<<m<<endl;
    //cout<<x<<" ~ "<<endl;
    return x;
}


int main()
{
    long long a,b,m;
    cin>>a>>b>>m;
    cout<<bigmod(a,b,m)<<endl;
}
