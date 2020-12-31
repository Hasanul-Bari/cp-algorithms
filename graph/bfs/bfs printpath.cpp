#include<bits/stdc++.h>
using namespace std;

map<string,string> p;

void printpath(string u,string s)
{
    if(u==s)
    {
        //cout<<s<<" "<<u<<endl;
        return ;
    }
    printpath(p[u],s);

    cout<<p[u]<<" "<<u<<endl;
}

int main()
{
    int e;
    cin>>e;
    map <string, vector<string> > m;
    map <string, vector<string> > :: iterator it;

    string u,v;
    for(int i=0; i<e; i++)
    {
        cin>>u>>v;

        m[u].push_back(v);
        m[v].push_back(u);


    }

    for(it=m.begin(); it!=m.end(); it++)
    {
        for(int j=0; j<it->second.size(); j++)
        {
            cout<<it->first<<" "<<it->second[j]<<" ";
        }
        cout<<endl;
    }

    //cout<<m.size()<<endl;

    int n=m.size();

    string src,des;
    cin>>src>>des;


    queue <string> q;

    map<string,int> visited;
    map<string,int> level;

    visited[src]=1;


    q.push(src);

    while(q.empty()!=1)
    {
        string x=q.front();
        q.pop();
        for(int i=0; i<m[x].size(); i++)
        {
            string y=m[x][i];
            if(visited[y]==0)
            {
                visited[y]=1;
                level[y]=level[x]+1;
                q.push(y);
                p[y]=x;

            }
        }
    }

    cout<<"**"<<endl;

    if(src!=des && level[des]==0)
    {
        cout<<"No route"<<endl;
    }
    else
    {
        printpath(des,src);

    }




}
