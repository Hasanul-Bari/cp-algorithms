#include<bits/stdc++.h>
using namespace std;


int dp[10000];  ///memorization
int fibb(int n)
{
    if(n==1 || n==0)
        return 1;
    else if(dp[n]==0)
        dp[n]=fibb(n-1)+fibb(n-2);

    return  dp[n];
}


int main()
{
    int n;
    while(cin>>n)
    cout<<fibb(n-1)<<endl;
}


