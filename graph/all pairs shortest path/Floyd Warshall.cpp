#include<bits/stdc++.h>
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
using namespace std;

int next[100][100];
void findpath(int u,int v)
{
    cout<<u<<" -> ";
    while(u!=v)
    {
        u=next[u][v];
        if(u==-1)
        {
            cout<<endl;
            return;
        }
        cout<<u<<" -> ";
    }
    cout<<endl;
}

int main()
{
    faster
    int n,e;
    cin>>n>>e;
    int adj[n][n];
    //int next[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==j)
                adj[i][j]=0;
            else
                adj[i][j]=1e9;

            next[i][j]=-1;  ///nil
        }
    }
    int u,v,cost;
    for(int i=0; i<e; i++)
    {
        cin>>u>>v>>cost;
        adj[u][v]=cost;

        next[u][v]=v;
    }
    ///floydWarshall
    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(adj[i][j]>adj[i][k]+adj[k][j])
                {
                    adj[i][j]=adj[i][k]+adj[k][j];
                    next[i][j]=next[i][k];
                }

            }
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<<adj[i][j]<<" ";
        cout<<endl;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i!=j)
            {
                cout<<" path "<<i<<" -> "<<j<<" : ";
                findpath(i,j);
            }

        }

    }
    return 0;
}

/*
4 4
0 1 5
0 3 10
1 2 3
2 3 1
*/
