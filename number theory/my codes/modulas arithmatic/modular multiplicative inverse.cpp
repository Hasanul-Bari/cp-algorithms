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
    }

    else
    {
        gcdextendeuclid(b,a%b);
        int temp = x;
        x = y;
        y = temp - (a/b)*y;

    }

}


int modinverse(int b, int m)
{
    gcdextendeuclid(b,m);
    if(gcd!=1)
        return -1;
    else
    {
        int ans=((x%m)+m)%m;     // m is added to handle negative x
        return ans;
    }
}





int main()
{
    int b,m;
    cin>>b>>m;
    if(modinverse(b,m)==-1)
        cout<<"Inverse doesn't exist";
    else
        cout<<modinverse(b,m)<<endl;
}

