#include<bits/stdc++.h>

using namespace std;


int main()
{
    long long n;
    cin>>n;

    vector<bool> prime(n,true);
    vector<long long> a,b;

    for(long long i=2; i*i<=n; i++)
    {
        if(prime[i]==true)
        {
            for(long long j=i*i; j<=n; j=j+i)
                prime[j]=false;
        }
    }


    for(long long i=2; i<=n; i++)
    {
        if(prime[i]==true)
        {
            a.push_back(i);
            long long x=0,y;
            y=n;
            while(y!=0)
            {

                x=x+(y/i);
                y=y/i;
            }
            b.push_back(x);

        }
    }

    cout<<a.size()<<endl;
    cout<<b.size()<<endl;
    for(long long i=0; i<a.size(); i++)
    {
       cout<<a[i]<<"^"<<b[i]<<endl;
    }



    return 0;


}
