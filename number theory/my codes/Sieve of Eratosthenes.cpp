#include<bits/stdc++.h>

using namespace std;

void seiveoferatosthenis(int n)
{
    vector<bool> prime(n,true);
   // memset(prime,true,sizeof(prime));


    for(int i=2; i*i<=n; i++)
    {
        if(prime[i]==true)
        {
            for(int j=i*i; j<=n; j=j+i)
                prime[j]=false;
        }
    }

    for(int i=2; i<=n; i++)
    {
        if(prime[i]==true)
            cout<<i<<",";
    }


}

int main()
{
    int n;
    cin>>n;
    seiveoferatosthenis(n);

}

