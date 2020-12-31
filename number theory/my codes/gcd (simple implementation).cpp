#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    int ans=1;
    int x=min(a,b);

    for(int i=1; i<=x; i++)
    {
        if(a%i==0  && b%i==0)
        {
            ans=i;
        }
    }
    return ans;
}

int main()
{
    int a,b;
    cin>>a>>b;

    cout<<gcd(a,b)<<endl;
}
