#include<bits/stdc++.h>
using namespace std;

int main()
{
    int e;
    cin>>e;
    map <int, vector<int> > m;
    map <int, vector<int> > :: iterator it;

    int u,v;
    for(int i=0; i<e; i++)
    {
        cin>>u>>v;
        if(u!=v)
        {
            m[u].push_back(v);
            m[v].push_back(u);


        }
        else
            m[u].push_back(v);
    }
    cout<<m.size()<<endl;
    for(it=m.begin(); it!=m.end(); it++)
    {
        for(int j=0; j<it->second.size(); j++)
        {
            cout<<it->second[j]<<" ";
        }
        cout<<endl;
    }

    //cout<<m.size()<<endl;

    int n=m.size();

    int src;
    cin>>src;


    queue <int> q;

    map<int,int> visited;
    map<int,int> level;
    map<int,int> :: iterator itr;


    visited[src]=1;

    q.push(src);

    while(q.empty()!=1)
    {
        int x=q.front();
        q.pop();
        for(int i=0; i<m[x].size(); i++)
        {
            int y=m[x][i];
            if(visited[y]==0)
            {
                visited[y]=1;
                level[y]=level[x]+1;
                q.push(y);
            }
        }
    }

   for(itr=level.begin(); itr!=level.end(); itr++)
   {
       cout<<itr->first<<" "<<itr->second<<endl;
   }

    //cout<<visited.size()<<endl;








}

