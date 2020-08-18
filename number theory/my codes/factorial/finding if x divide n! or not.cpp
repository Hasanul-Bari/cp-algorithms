#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m;
    cin>>n>>m;

    vector<bool> prime(n,true);
    vector<long long> a,b,c;

    for(long long i=2; i*i<=65536; i++)
    {
        if(prime[i]==true)
        {
            for(long long j=i*i; j<=65536; j=j+i)
                prime[j]=false;
        }
    }
    int hp=0;
    long long xx=m;
    for(long long i=2; i*i<=m; i++)
    {
        if(prime[i]==true)
        {
            a.push_back(i);
            long long x=0,y,p=i;
            y=n;
            while(p<=n)
            {

                x=x+(y/p);
                p=p*i;
            }
            b.push_back(x);

            int cc=0;

            if(xx%i==0)
            {
                while(xx%i==0)
                {
                    cc++;
                    xx=xx/i;
                }
            }
            c.push_back(cc);
            if(cc>x)
            {
                hp=1;
                break;
            }

        }
    }



    cout<<a.size()<<endl;
    cout<<b.size()<<endl;
    cout<<b.size()<<endl;

    for(long long i=0; i<a.size(); i++)
    {
       cout<<a[i]<<" -> "<<b[i]<<" "<<c[i]<<endl;
    }



    if(hp==1)
        cout<<m<<" does not divide "<<n<<"!"<<endl;
    else
    cout<<m<<" divides "<<n<<"!"<<endl;
    return 0;
}
