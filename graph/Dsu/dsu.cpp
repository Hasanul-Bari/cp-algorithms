#include<bits/stdc++.h>
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define pb push_back
const double PI = acos(-1.0);
using namespace std;

map<int,int> p;
map<int,int> sz;

int find_set(int v)
{
    if(v==p[v])
        return v;

    return p[v]=find_set(p[v]);
}

void union_set(int a,int b)
{
    int u=find_set(a);
    int v=find_set(b);

    if(u!=v)
    {
        if(sz[u]<sz[v])
            swap(u,v);

        p[v]=u;
        sz[u]=sz[u]+sz[v];
    }

}
int main()
{
    faster

    int n;
    cin>>n;

    for(int i=1; i<=n; i++)           ///make set
    {
        p[i]=i;
        sz[i]=1;
    }
    return 0;
}
