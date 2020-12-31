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

    cout<<(1<<n)<<endl;


    for(int i=0; i<(1<<n); i++)
    {
        cout<<bitset<3>(i)<<" -> "<<__builtin_popcount(i)<<endl;

        int num=i;

        while(num)
        {
            cout<<bitset<3>(num)<<endl;
            num=num>>1;
        }

    }




    return 0;
}
