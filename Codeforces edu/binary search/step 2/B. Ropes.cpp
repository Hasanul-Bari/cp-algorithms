#include<bits/stdc++.h>
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define pb push_back
const double PI = acos(-1.0);
using namespace std;

//author: Hasanul Bari
int n,k;
double a[10000];

bool good(double x)
{
    int cnt=0;

    for(int i=0; i<n; i++)
    {
        cnt+=floor(a[i]/x);
    }

    return cnt>=k;
}

void solve(int tc)
{
    cin>>n>>k;

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    double l=0; // l is good
    double r=1e8; // r is bad

    for(int i=1; i<=100; i++)
    {
        double m=(l+r)/2.0;

        if(good(m)){
            l=m;
        }
        else{
            r=m;
        }
    }


    //cout<<l<<endl;

    printf("%.20lf\n",l);
}


int main()
{
    faster

    //int t; cin>>t; for(int tc=1; tc<=t; tc++)solve(tc);

    solve(1);



    return 0;
}



