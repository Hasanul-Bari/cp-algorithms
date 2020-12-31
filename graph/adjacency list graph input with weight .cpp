#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;
    cin>>n>>e;

    vector <int> adj[n+1];
    vector <int> cost[n+1];


    int u,v,w;
    for(int i=0; i<e; i++)
    {
        cin>>u>>v>>w;
        if(u!=v)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        else
        {
            adj[u].push_back(v);
            cost[u].push_back(w);
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<adj[i].size(); j++)
        {
            cout<<adj[i][j]<<" ("<<cost[i][j]<<")    ";
        }
        cout<<endl;
    }
}

