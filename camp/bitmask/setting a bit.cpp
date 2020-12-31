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

    int x,i;
    cin>>x;

    cout<<x<<" in binary: ";
    cout<<bitset<32>(x)<<endl;

    cout<<"No of set(1) bits : ";
    cout<<__builtin_popcount(x)<<endl;

    cout<<"count trailing zeros: ";
    cout<<__builtin_ctz(x)<<endl;

    cout<<"count trailing zeros: ";
    cout<<__builtin_clz(x)<<endl;


    cout<<"Set the ith(from left from 0) bit : "<<endl;
    cin>>i;
    cout<<bitset<32>(x |(1<<i) )<<endl;

    cout<<"ReSet the ith(from left from 0) bit : "<<endl;
    cin>>i;
    cout<<bitset<32>(x & ~(1<<i) )<<endl;


    cout<<"Flip the ith(from left from 0) bit : "<<endl;;
    cin>>i;
    cout<<bitset<32>(x ^ (1<<i) )<<endl;


    cout<<"Testing the ith(from left from 0) bit set/reset: "<<endl;
    cin>>i;
    cout<<(x&(1<<i))<<endl;








    return 0;
}
