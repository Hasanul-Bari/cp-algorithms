#include<bits/stdc++.h>
using namespace std;


vector <int> adj[1000];
bool visited[1000]= {false};
int level[1000];


void dfs(int s)
{
    if (visited[s])
        return;
    visited[s] = true;
// process node s
    for (int u=0; u<adj[s].size(); u++)
    {
        dfs(u);
    }
}

int main()
{
    int n,e;
    cin>>n>>e;


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

    int src;
    cin>>src;


    visited[src]=true;
    level[src]=0;

    dfs(src);




}


