#include<bits/stdc++.h>
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define pb push_back
const double PI = acos(-1.0);
using namespace std;

//author: Hasanul Bari

bool binarySearch(int a[],int n,int x)
{
    int l=0,r=n-1;

    while(r>=l)
    {
        int m=(l+r)/2;

        if(a[m]==x)
        {
            return true;
        }
        else if(a[m]<x)
        {
            l=m+1;
        }
        else if(a[m]>x)
        {
            r=m-1;
        }
    }

    return false;
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

        if(binarySearch(a,n,x))
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }



}


int main()
{
    faster

    //int t; cin>>t; for(int tc=1; tc<=t; tc++)solve(tc);

    solve(1);



    return 0;
}


