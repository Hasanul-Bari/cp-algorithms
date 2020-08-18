#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int divisor=0;
    for(int i=1; i<=n; i++)
    {
        if(n%i==0)
        {
            divisor++;
        }
    }
    cout<<"Divisors = "<<divisor<<endl;
    return 0;
}
