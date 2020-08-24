#include<bits/stdc++.h>
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define pb push_back
const double PI = acos(-1.0);
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


    for(int i=0; i<=n; i++)
    {
        for(int w=0; w<=c; w++)
        {
            cout<<k[i][w]<<" ";
        }
        cout<<"*"<<endl;
    }

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

