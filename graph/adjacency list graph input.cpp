#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;
    cin>>n>>e;

    vector <int> adj[n+1];

    int u,v;
    for(int i=0; i<e; i++)
    {
        cin>>u>>v;
        if(u!=v)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        else
            adj[u].push_back(v);
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<adj[i].size(); j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}
