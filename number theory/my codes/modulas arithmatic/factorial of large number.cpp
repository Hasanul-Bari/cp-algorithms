#include<bits/stdc++.h>
using namespace std;

//const unsigned long long m=1000000007;

unsigned long long factorial(int n)
{
    const unsigned  int m=1000000007;
    unsigned long long f=1;
    for(int i=1; i<=n; i++)
    {
        f=(f*i)%m;
        //f=((f%m)*(i%m))%m;
    }
    return f;
}

int main()
{
    int n;
    cin>>n;
    cout<<factorial(n)<<endl;
}
