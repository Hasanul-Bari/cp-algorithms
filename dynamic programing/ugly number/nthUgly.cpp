#include<bits/stdc++.h>
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define pb push_back
const double PI = acos(-1.0);
using namespace std;

int nthUglyNumber(int n)
{

    int ugly[n];

    int l2=0,l3=0,l5=0;

    int next_multiple_of_2 =2;
    int next_multiple_of_3=3;
    int next_multiple_of_5=5;

    ugly[0]=1;


    for(int i=1; i<n; i++)
    {

        ugly[i]=min(next_multiple_of_2,min(next_multiple_of_3,next_multiple_of_5));

        if(ugly[i]==next_multiple_of_2)
        {
            l2++;
            next_multiple_of_2=ugly[l2]*2;
        }

        if(ugly[i]==next_multiple_of_3)
        {
            l3++;
            next_multiple_of_3=ugly[l3]*3;
        }

        if(ugly[i]==next_multiple_of_5)
        {
            l5++;
            next_multiple_of_5=ugly[l5]*5;
        }

        //cout<<i<<" "<<ugly[i]<<endl;
        //cout<<next_multiple_of_2<<" "<<next_multiple_of_3<<" "<<next_multiple_of_5<<endl;
    }


    return ugly[n-1];
}

int main()
{
    faster

    int n;
    cin>>n;

    cout<<nthUglyNumber(n)<<endl;




    return 0;
}
