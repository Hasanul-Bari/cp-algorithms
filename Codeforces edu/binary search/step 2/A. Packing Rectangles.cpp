#include<bits/stdc++.h>
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define pb push_back
const double PI = acos(-1.0);
using namespace std;

//author: Hasanul Bari


void solve(int tc)
{
    ll w,h,n;

    cin>>w>>h>>n;

    ll l=0, r=1;

    while((r/w)*(r/h)<n)
    {
        r=r*2;
    }

    while(r>l+1)
    {
        ll m=(l+r)/2;

        //cout<<m<<" "<<r<<endl;


        if((m/w)*(m/h)>=n)
        {
            r=m;
        }
        else
        {
            l=m;
        }

    }

    cout<<r<<endl;

}


int main()
{
    faster

    //int t; cin>>t; for(int tc=1; tc<=t; tc++)solve(tc);

    solve(1);



    return 0;
}


