#include<bits/stdc++.h>
using  namespace std;

int gcd(int a,int b)
{
    int temp;
    while(b!=0)
    {
        temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

int main()
{
   int a,b;
   cin>>a>>b;
   cout<<gcd(a,b)<<endl;
}

