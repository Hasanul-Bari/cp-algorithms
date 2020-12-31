#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int divisor=0;
    for(int i=1; i*i<=n; i++)
    {
        if(i*i==n)
        {
            divisor++;
            cout<<i<<" X "<<i<<endl;
        }
        else if(n%i==0)
        {
            divisor=divisor+2;
            cout<<i<<" X "<<n/i<<endl;
        }

    }
    cout<<"Divisors = "<<divisor<<endl;
    return 0;
}
