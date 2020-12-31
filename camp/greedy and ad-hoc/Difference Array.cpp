#include<bits/stdc++.h>
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define pb push_back
const double PI = acos(-1.0);
using namespace std;

int main()
{
    faster

    int n;
    cin>>n;

    int a[n];

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    ///create diff array

    int diff[n];
    for(int i=0; i<n; i++)
    {
        if(i==n-1)
            diff[i]=-a[i];
        else
            diff[i]=a[i+1]-a[i];

        cout<<diff[i]<<" ";
    }
    cout<<endl;

    int q,l,r,x;
    cin>>q;

    while(q--)
    {
        cin>>l>>r>>x;

        if(l-1<0)
            a[0]=a[0]+x;
        else
            diff[l-1]=diff[l-1]+x;

        diff[r]=diff[r]-x;



    }

    for(int i=1; i<n; i++)
    {
        a[i]=diff[i-1]+a[i-1];
    }

    cout<<"Array"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;










    return 0;
}
