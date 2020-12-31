#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,e;
    cin>>n>>e;
    int a[n][n];
    memset(a,0,sizeof(a));

    int u,v,cost;
    for(int i=0; i<e; i++)
    {
        cin>>u>>v>>cost;
        a[u-1][v-1]=cost;
        a[v-1][u-1]=cost;
    }




    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }


}
