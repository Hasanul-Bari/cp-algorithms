#include<bits/stdc++.h>
using namespace std;


void toitent(int n)
{
    int phi[n+1];
    for(int i=1; i<=n; i++)
    {
        phi[i]=i;
    }

    for(int i=2; i<=n; i++)
    {
        if(phi[i]==i)
        {
            phi[i]=i-1;
            for(int j=2*i;  j<=n; j=j+i)
            {
                phi[j]=phi[j]-phi[j]/i;
            }
        }
    }

    for (int i=1; i<=n; i++)
      cout <<"Totient of "<<i<<" is "<<phi[i]<< endl;


}

int main()
{
    int n;
    cin>>n;
    toitent(n);
}
