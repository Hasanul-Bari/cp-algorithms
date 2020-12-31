#include<bits/stdc++.h>
using namespace std;

int x,y,gcd;

void gcdextendeuclid(int a,int b)
{
    if(b==0)
    {
        x=1;
        y=0;
        gcd=a;
       // cout<<x<<" "<<y<<" ^ "<<endl;
    }

    else
    {
        gcdextendeuclid(b,a%b);
        int temp = x;
        x = y;
        y = temp - (a/b)*y;
        //cout<<x<<" "<<y<<" * "<<<endl;

    }
    //cout<<x<<" "<<y<<endl;
    //cout<<a<<" "<<b<<endl;
}


int main()
{
    int a,b;
    cin>>a>>b;
    gcdextendeuclid(a,b);
    cout<<"x= "<<x<<" "<<"y= "<<y<<" "<<"gcd= "<<gcd<<endl;
}
