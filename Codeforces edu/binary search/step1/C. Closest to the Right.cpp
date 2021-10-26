#include<bits/stdc++.h>
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define pb push_back
const double PI = acos(-1.0);
using namespace std;

//author: Hasanul Bari

int closeToRight(int a[],int n,int x)
{
    int l=-1;  //a[l]<x
    int r=n;   //a[r]>=x

    while(r>l+1)   // atleast 3 elem
    {
        int m=(l+r)/2;

        if(a[m]<x)
        {
            l=m;
        }
        else
        {
            r=m;
        }
    }

    return r+1;
}

void solve(int tc)
{
    int n,k,x;
    cin>>n>>k;
    int a[n];

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    while(k--)
    {
        cin>>x;

        cout<<closeToRight(a,n,x)<<endl;
    }



}


int main()
{
    faster

    //int t; cin>>t; for(int tc=1; tc<=t; tc++)solve(tc);

    solve(1);



    return 0;
}




