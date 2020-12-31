#include<bits/stdc++.h>
using namespace std;

long long binomial_coefficient(long long n, long long k)
{
    long long c[n+1][k+1];
    for(long long i=0; i<=n; i++)
    {
        for(long long j=0; j<=min(i,k); j++)
        {
            if(j==0 || j==i)
                c[i][j]=1;
            else
                c[i][j]=c[i-1][j-1]+c[i-1][j];
        }
    }

    for(long long i=0; i<=n; i++)
    {
        for(long long j=0; j<=min(i,k); j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    return c[n][k];
}

int main()
{
    long long n,k;
    cin>>n>>k;
    cout<<binomial_coefficient(n,k)<<endl;
}
