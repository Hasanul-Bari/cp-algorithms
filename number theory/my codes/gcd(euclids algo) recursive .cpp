#include<bits/stdc++.h>
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define pb push_back
const double PI = acos(-1.0);
using namespace std;

int gcd(int a,int b)
{
    if(b==0)
        return a;

    return gcd(b,a%b);
}

int main()
{
   int a,b;
   cin>>a>>b;
   cout<<gcd(a,b)<<endl;
   cout<<(a*b)/gcd(a,b)<<endl;
}
