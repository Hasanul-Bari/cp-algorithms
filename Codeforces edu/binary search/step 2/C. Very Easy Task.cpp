#include<bits/stdc++.h>
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define pb push_back
const double PI = acos(-1.0);
using namespace std;

//author: Hasanul Bari

ll n,x,y;

bool good(ll t)
{
    ll cnt=0;

    if(t>=min(x,y))
    {
        cnt++;
        t=t-min(x,y);
    }

    cnt+=(t/x)+(t/y);

    return cnt>=n;
}

void solve(int tc)
{


    cin>>n>>x>>y;

    ll l=0, r=max(x,y)*n;

    while(r>l+1)
    {
        ll m=(l+r)/2;

        //cout<<m<<" "<<good(m)<<endl;

        if(good(m)){
            r=m;

        }
        else{
            l=m;
        }

        //cout<<l<<" ** "<<r<<endl;

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


