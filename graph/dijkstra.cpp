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
        adj[u].push_back(v);
        adj[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);

    }

    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<adj[i].size(); j++)
        {
            cout<<adj[i][j]<<" ("<<cost[i][j]<<")    ";
        }
        cout<<endl;
    }
    int src=1;
    //cin>>src;

    int d[n+1];
    for(int i=1; i<=n; i++)
        d[i]=INT_MAX;

    priority_queue <int> q;


    d[src]=0;

    q.push(src);

    while(q.empty()!=1)
    {
        int x=q.top();
        q.pop();
        for(int i=0; i<adj[x].size(); i++)
        {
            int y=adj[x][i];
            if(d[x]+cost[x][i]<d[y])
            {
                d[y]=d[x]+cost[x][i];
                q.push(y);
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        cout<<i<<" "<<d[i]<<endl;
    }


}

/*

6 8
1 2 2
1 3 4
2 4 7
3 5 3
2 3 1
4 5 2
4 6 1
5 6 5

*/


