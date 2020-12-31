#include<bits/stdc++.h>
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
const double PI = acos(-1.0);
using namespace std;

struct cell
{
    int x,y;
};

int mx[4]= {-1,1,0,0};
int my[4]= {0,0,-1,1};

int main()
{
    faster
    int r,c,e;
    cin>>r>>c>>e;
    bool a[r+1][c+1];
    for(int i=1; i<=r; i++)
        for(int j=1; j<=c; j++)
            a[i][j]=false;


    int u,v;
    for(int i=0; i<e; i++)
    {
        cin>>u>>v;
        a[u][v]=true;
    }

    cell src,des;


    while(cin>>src.x>>src.y>>des.x>>des.y)
    {

        //cout<<src.x<<" "<<src.y<<" "<<des.x<<" "<<des.y<<endl;
        //cout<<src<<" "<<des<<endl;


        bool visited[r+1][c+1];
        int level[r+1][c+1]= {0};

        for(int i=1; i<=r; i++)
            for(int j=1; j<=c; j++)
                visited[i][j]=false;

        queue <cell> q;

        visited[src.x][src.y]=true;
        level[src.x][src.y]=0;

        q.push(src);

        while(q.empty()!=1)
        {
            cell u=q.front();
            q.pop();
            for(int i=0; i<4; i++)
            {
                cell v;
                v.x=u.x+mx[i];
                v.y=u.y+my[i];
                if( (v.x>=1 && v.x<=r) && (v.y>=1 && v.y<=c ) &&  visited[v.x][v.y]==false)
                {
                    visited[v.x][v.y]=true;
                    level[v.x][v.y]=(level[u.x][u.y])+1;
                    q.push(v);
                }
            }
        }

        cout<<level[des.x][des.y]<<endl;

    }

    return 0;


}



