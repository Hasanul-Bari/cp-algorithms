#include<bits/stdc++.h>
using namespace std;

int wt[1000];
int p[1000];

int knapsack(int c, int n)
{
    int k[n+1][c+1];

    for(int i=0; i<=n; i++)
    {
        for(int w=0; w<=c; w++)
        {

            if(i==0 || w==0)
                k[i][w]=0;

            else if(wt[i]<=w)
                k[i][w]=max( k[i-1][w], p[i]+k[i-1][w-wt[i]] );
            else
                k[i][w]=k[i-1][w];


        }
    }

    int a[n+1]={0};
    int rem=k[n][c],w=c;
    for(int i=n; i>0; i--)
    {
        if(rem!=k[i-1][w])
        {
            a[i]=1;
            rem=rem-p[i];
            w=w-wt[i];
        }
        //cout<<a[i]<<endl;
        /*if(rem<0)
            break;*/
    }


    for(int i=1; i<=n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;


    return k[n][c];
}


int main()
{
    int n,c;
    cin>>n>>c;


    for(int i=1; i<=n; i++)
        cin>>wt[i];

    for(int i=1; i<=n; i++)
        cin>>p[i];

    cout<<knapsack(c,n)<<endl;
}

/*

4 20
5 10 3 12
10 40 50 75

*/

/*
4 8
2 3 4 5
1 2 5 6
*/
