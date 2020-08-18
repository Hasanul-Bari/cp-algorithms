#include<bits/stdc++.h>
using namespace std;

int fibb(int n)
{
    if(n==1)
        return 1;
    if(n==0)
        return 0;

    return  fibb(n-1)+fibb(n-2);
}


int main()
{
    int n;
    while(cin>>n)
    cout<<fibb(n)<<endl;
}

