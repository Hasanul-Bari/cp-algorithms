#include<bits/stdc++.h>
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
using namespace std;

map<int,int> p;

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

bool bellmenford(vector<int> adj[],vector<int> w[],int n,ll d[])
{



    for(int i=1; i<n; i++)
    {
        for(int u=1; u<=n; u++)
        {
            for(int j=0; j<adj[u].size(); j++)
            {
                int v=adj[u][j];

                if(d[u]+w[u][j]<d[v])
                {
                    d[v]=d[u]+w[u][j];
                    p[v]=u;
                }
            }
        }
    }


    for(int u=1; u<=n; u++)
    {
        for(int j=0; j<adj[u].size(); j++)
        {
            int v=adj[u][j];

            if(d[u]+w[u][j]<d[v])
            {
                return false;
            }
        }
    }

    return true;
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
        //adj[v].push_back(u);
        w[u].push_back(z);
        //w[v].push_back(z);
    }

    ll d[n+1];
    for(int i=1; i<=n; i++)
    {
        d[i]=1e18;
    }

    int src;
    cin>>src;

    d[src]=0;

    if(bellmenford(adj,w,n,d)==true)
    {
        cout<<"No negative weight cycle"<<endl;
        ///path printing
        for(int i=1; i<=n; i++)
        {
            cout<<"Distance from "<<src<<" to "<<i<<" : "<<d[i]<<" and path : ";

            if(d[i]==1e18)
                cout<<"No path"<<endl;
            else
            {
                printpath(i,src);
                cout<<endl;
            }

        }
    }
    else
        cout<<"Negative weight cycle"<<endl;



    return 0;
}

/*

5 10
0 1 10
0 2 5
1 2 2
2 1 3
1 3 1
2 4 2
2 3 9
4 0 7
4 3 6
3 4 4
*/

/*
5 10
1 2 10
1 3 5
2 3 2
3 2 3
2 4 1
3 5 2
3 4 9
5 1 7
5 4 6
4 5 4
*/

///negative weight
/*

5 10
1 2 6
1 3 7
2 3 8
2 4 5
4 2 -2
3 5 9
3 4 -3
2 5 -4
5 4 7
5 1 2

*/


