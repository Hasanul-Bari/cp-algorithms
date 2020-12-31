#include<bits/stdc++.h>
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
using namespace std;


map<int,int> p;

class node
{
public:
    int name;
    int cost;
    int par;

    node() {}

    node(int n,int c)
    {
        name=n;
        cost=c;
        par=0;
    }

};

bool operator<(node a,node b)   ///makes the priority queue as min cost node at top
{
    return b.cost<a.cost;
}

void printpath(int u,int s)
{
    if(u==s)
    {
        cout<<u<<" ";
        return ;
    }
    printpath(p[u],s);

    cout<<u<<" ";

}

int main()
{
    faster

    int n,e;
    cin>>n>>e;
    vector <int> adj[n+1];
    vector <int> w[n+1];

    int u,v,z;
    for(int i=0; i<e; i++)
    {
        cin>>u>>v>>z;
        adj[u].push_back(v);
        adj[v].push_back(u);
        w[u].push_back(z);
        w[v].push_back(z);
    }

    int src;
    cin>>src;

    int key[n+1];
    bool visited[n+1]= {false};

    for(int i=1; i<=n; i++)
    {
        key[i]=1e9;
        visited[i]=false;
    }



    int c=0,ans=0;

    priority_queue <node> q;
    visited[src]=true;
    key[src]=0;

    for(int i=0; i<adj[src].size(); i++)
    {
        int v=adj[src][i];
        node temp(v,w[src][i]);
        temp.par=src;
        k[i]=w[src][i];

        q.push(temp);
    }


    while(1)
    {
        node top=q.top();
        int u=top.name;

        p[u]=top.par;

        q.pop();
        if(visited[u]==false)
        {

            for(int i=0; i<adj[u].size(); i++)
            {
                int v=adj[u][i];
                node temp(v,w[u][i]);

                temp.par=u;
                q.push(temp);

            }
            c++;
            visited[u]=true;
            //cout<<top.cost<<endl;
            ans=ans+top.cost;

            if(c==n-1)
                break;

        }


    }
    cout<<ans<<endl;

    for(int i=1; i<=n; i++)
        cout<<p[i]<<" -- "<<i<<endl;




    return 0;
}

/*

7 9
1 6 10
1 2 28
5 6 25
5 7 24
7 2 14
5 4 22
7 4 18
2 3 16
4 3 12

*/


/*

6 9
1 2 7
1 3 8
2 3 3
2 4 6
3 4 4
3 5 3
4 6 5
4 5 2
5 6 2

*/
