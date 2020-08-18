#include<bits/stdc++.h>
using namespace std;

vector<int> primes;

void divisorcount(int n)
{
    int divisor=1;
    for(int i=0; i<primes.size()/2; i++)
    {

        if(n%primes[i]==0)
        {
            int c=0;
            while(n%primes[i]==0)
            {
                n=n/primes[i];
                c++;
            }

            divisor=divisor*(c+1);
        }

    }

    cout<<divisor<<endl;

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
    divisorcount(n);

    return 0;

}

