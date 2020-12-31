#include<bits/stdc++.h>
using namespace std;

vector<int> primes;

int phi(int n)
{
    int ans=n;
    for(int i=0; i<primes.size(); i++)
    {
        if(n%primes[i]==0)
        {
           ans=ans-(ans/primes[i]);
        }
    }
    return ans;
}




void seiveoferatosthenis(int n)
{
    vector<bool> prime(n,true);

    for(int i=2; i*i<=n; i++)
    {
        if(prime[i]==true)
        {
            for(int j=i*2; j<=n; j=j+i)
                prime[j]=false;
        }
    }

    for(int i=2; i<=n; i++)
    {
        if(prime[i]==true)
            primes.push_back(i);
    }


}

int main()
{
    int n;
    cin>>n;
    seiveoferatosthenis(n);
    for(int i=1; i<=n; i++)
     cout<<phi(i)<<endl;
}

