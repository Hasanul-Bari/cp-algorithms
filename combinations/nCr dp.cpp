#include<bits/stdc++.h>
using namespace std;

int dp[10000][10000];
long long nCr(long long n, long long r)
{
    if(r==1)
        return n;
    else if(r==n)
        return 1;

    else if(dp[n][r]==0)
        dp[n][r]=nCr(n-1,r-1)+nCr(n-1,r);

    return dp[n][r];
}
int main()
{
    long long n,k;
    cin>>n>>k;
    cout<<nCr(n,k)<<endl;
}
