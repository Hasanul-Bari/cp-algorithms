#include<bits/stdc++.h>
using namespace std;

int phi(int n)
{
    int ans=n;
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                n=n/i;
            }

            ans=ans-(ans/i);
        }
    }
    if(n>1)
        ans=ans-(ans/n);

    return ans;
}

int main()
{
    int n;
    cin>>n;
    //for(int i=1; i<=n; i++)
        cout<<phi(n)<<endl;
}
