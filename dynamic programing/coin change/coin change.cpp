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

    int n,target;
    cin>>n;
    int coin[n];
    for(int i=0; i<n; i++)
        cin>>coin[i];

    cin>>target;

    int a[target+1];
    a[0]=0;

    for(int i=1; i<=target; i++)
    {
        a[i]=target+1;
        for(int j=0; j<n; j++)
        {
            if(i>=coin[j]  &&  a[i]>  a[i-coin[j]]+1  )
                a[i]=a[i-coin[j]]+1;
        }
    }

    cout<<a[target]<<endl;



}
