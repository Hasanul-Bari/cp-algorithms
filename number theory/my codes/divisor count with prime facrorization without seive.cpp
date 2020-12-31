#include<bits/stdc++.h>
using namespace std;


void divisorcount(int n)
{
    int divisor=1;
    for(int i=2; i*i<=n; i++)
    {

        if(n%i==0)
        {
            int c=0;
            while(n%i==0)
            {
                n=n/i;
                c++;
            }

            divisor=divisor*(c+1);
        }

    }
    if(n>1)
        divisor=divisor*2;

    cout<<divisor<<endl;

}



int main()
{
    int n;
    cin>>n;
    divisorcount(n);

    return 0;

}


