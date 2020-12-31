#include<bits/stdc++.h>
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
using namespace std;

vector <int> adj[100];
bool visited[100];     // default initialize to false/0
int d[100];
int f[100];
int t;


stack<int> s;


void dfs(int src)
{

    visited[src]=true;
    t++;
    d[src]=t;
    //cout<<src<<" ";
    for(int i=0; i<adj[src].size(); i++)
    {
        int x=adj[src][i];
        //cout<<"x"<<endl;
        if(visited[x]==false)
        {
            dfs(x);
        }

    }

    s.push(src);

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

    /*for(int i=1; i<=n; i++)
    {
        for(int j=0; j<adj[i].size(); j++)
        {
            cout<<i<<" "<<adj[i][j]<<" ";
        }
        cout<<endl;
    }*/

    //int src;
    //cin>>src;

    for(int i=1; i<=n; i++)
    {
        if(visited[i]==false)
            dfs(i);
    }


    while(s.empty()!=1)
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}

/*
8 9
1 2
1 5
2 4
2 6
2 7
4 8
6 8
5 8
5 7
*/

