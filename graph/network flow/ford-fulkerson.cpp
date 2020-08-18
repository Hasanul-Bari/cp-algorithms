#include<bits/stdc++.h>
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
using namespace std;

map<int,int> p;

bool bfs(vector<int> adj[],map< pair<int,int>, int> c,int n,int src,int dest)
{
    bool visited[n+1]= {false};
    queue <int> q;

    visited[src]=true;


    q.push(src);

    while(q.empty()!=1)
    {
        int x=q.front();
        q.pop();
        for(int i=0; i<adj[x].size(); i++)
        {
            int y=adj[x][i];
            if(visited[y]==false && c[{x,y}]>0)
            {
                visited[y]=true;
                p[y]=x;
                q.push(y);
            }
        }
    }



    return (visited[dest]==true);

}

int ford_fulkerson(vector<int> adj[],map< pair<int,int>, int> c,int n,int src,int dest)
{


    int max_flow=0;

    while(bfs(adj,c,n,src,dest))
    {
        cout<<"Hp"<<endl;
        int path_flow=1e9;



        for(int v=dest; v!=src; v=p[v])
        {
            int u=p[v];
            cout<<v<<" -> "<<u<<endl;
            path_flow=min(path_flow,c[{u,v}]);
        }

        for(int v=dest; v!=src; v=p[v])
        {
            int u=p[v];
            c[{u,v}]=c[{u,v}]-path_flow;
            c[{v,u}]=c[{v,u}]+path_flow;

        }



        max_flow=max_flow+path_flow;
        p.clear();

        cout<<"path_flow = "<<path_flow<<endl;
        cout<<"max_flow = "<<max_flow<<endl;

    }

    return max_flow;


}


int main()
{
    faster

    int n,e;
    cin>>n>>e;
    vector <int> adj[n+1];
    //vector<int> c[n+1];
    map< pair<int,int>, int> c;

    int u,v,z;
    for(int i=0; i<e; i++)
    {
        cin>>u>>v>>z;
        adj[u].push_back(v);
        adj[v].push_back(u);
        c[{u,v}]=z;

    }

    int src,dest;
    cin>>src>>dest;

    cout<<ford_fulkerson(adj,c,n,src,dest)<<endl;;






    return 0;
}

/*
6 9
1 2 16
1 3 13
3 2 4
2 4 12
3 5 14
4 3 9
5 4 7
4 6 20
5 6 4
1 6
*/

/*
6 8
1 2 10
1 3 8
2 4 5
2 3 2
3 5 10
5 4 8
4 6 7
5 6 10
1 6
*/

/*
4 5
1 2 3
1 3 2
2 3 5
2 4 2
3 4 3
1 4
*/



