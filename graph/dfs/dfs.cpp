#include<bits/stdc++.h>
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define pb push_back
const double PI = acos(-1.0);
using namespace std;

vector <int> adj[100];
bool visited[100];     // default initialize to false/0
int d[100];
int f[100];
int t;


void dfs(int src)
{

    visited[src]=true;
    t++;
    d[src]=t;
    cout<<src<<" ";
    for(int i=0; i<adj[src].size(); i++)
    {
        int x=adj[src][i];
        //cout<<"x"<<endl;
        if(visited[x]==false)
        {
            dfs(x);
        }

    }

    t++;
    f[src]=t;
}

int main()
{
    faster

    int n,e;
    cin>>n>>e;


    int u,v;
    for(int i=0; i<e; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);    ///directed edge
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<adj[i].size(); j++)
        {
            cout<<i<<" "<<adj[i][j]<<" ";
        }
        cout<<endl;
    }

    int src;
    cin>>src;


    dfs(src);
    cout<<endl;


    for(int i=1; i<=n; i++)
    {
        cout<<i<<" "<<d[i]<<" "<<f[i]<<endl;
    }

    return 0;
}
/*
8 14
1 4
1 2
1 7
2 5
2 7
3 2
3 5
3 8
4 6
4 7
5 7
6 1
7 6
8 7
*/
