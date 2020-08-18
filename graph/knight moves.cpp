#include<bits/stdc++.h>
using namespace std;

struct cell
{
    int x,y;
};


int kx[8]= {-2,-1,1,2,2,1,-1,-2};
int ky[8]= {1,2,2,1,-1,-2,-2,-1};

int main()
{
    struct cell src,des;
    string srcc,dest;

    while(cin>>srcc>>dest)
    {

        src.x=srcc[0]-96;
        src.y=srcc[1]-48;

        des.x=dest[0]-96;
        des.y=dest[1]-48;


        //cout<<src.x<<" "<<src.y<<" "<<des.x<<" "<<des.y<<endl;

        //cout<<src<<" "<<des<<endl;


        bool visited[9][9]= {false};
        int level[9][9]={0};
        queue <cell> q;

        visited[src.x][src.y]=true;
        level[src.x][src.y]=0;

        q.push(src);

        while(q.empty()!=1)
        {
            struct cell u=q.front();
            q.pop();
            for(int i=0; i<8; i++)
            {
                struct cell v;
                v.x=u.x+kx[i];
                v.y=u.y+ky[i];
                if( (v.x>=1 && v.x<=8) && (v.y>=1 && v.y<=8 ) &&  visited[v.x][v.y]==false)
                {
                    visited[v.x][v.y]=true;
                    level[v.x][v.y]=(level[u.x][u.y])+1;
                    q.push(v);
                }
            }
        }

        cout<<"To get from "<<srcc<<" to "<<dest<<" takes "<<level[des.x][des.y]<<" knight moves."<<endl;

    }

    return 0;


}

