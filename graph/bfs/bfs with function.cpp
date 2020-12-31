#include<bits/stdc++.h>
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
using namespace std;

void bfs(vector<int> adj[],int n,int src,int dest)
{
    bool visited[n+1]={false};
    int level[n+1];
    queue <int> q;

    visited[src]=true;
    level[src]=0;

    q.push(src);

    while(q.empty()!=1)
    {
        int x=q.front();
        q.pop();
        for(int i=0; i<adj[x].size(); i++)
        {
            int y=adj[x][i];
            if(visited[y]==false)
            {
                visited[y]=true;
                level[y]=level[x]+1;
                q.push(y);
            }
        }
    }


    for(int i=1; i<=n; i++)
        cout<<i<<" "<<level[i]<<endl;
}

int main()
{
    faster

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

    int src,dest;
    cin>>src>>dest;

    bfs(adj,n,src,dest);

    return 0;
}
