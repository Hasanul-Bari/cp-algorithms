#include<bits/stdc++.h>
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define pb push_back
const double PI = acos(-1.0);
using namespace std;

ll a[100009];
class info
{
public:
    ll p,ng;
    info() {}
    info(ll pp,ll nn)
    {
        p=pp;
        ng=nn;
    }

};

info tree[400099];

class ret
{
public:
    ll v,len;
    ret()
    {

    }
    ret(ll vv, ll ln)
    {
        v=vv;
        len=ln;
    }
};

void seg(ll node,ll b,ll e)
{
    if(b==e)
    {
        tree[node].p=a[b];
        tree[node].ng=-a[b];
        return;
    }

    ll left=node*2;
    ll right=(node*2)+1;

    ll mid=(b+e)/2;

    seg(left,b,mid);
    seg(right,mid+1,e);

    if((mid-b+1)%2==0)
    {
        tree[node].p=tree[left].p+tree[right].p;
        tree[node].ng=tree[left].ng+tree[right].ng;
    }
    else
    {
        tree[node].p=tree[left].p+tree[right].ng;
        tree[node].ng=tree[left].ng+tree[right].p;
    }


}

ret query(ll node,ll b,ll e,ll i,ll j,ll type)   //type 0 postive , 1 negative
{

    //cout<<node<<" type "<<type<<endl;

    if(i>e || j<b)
        return ret(1e16,0);   ///outside segment

    if(i<=b && e<=j)        ///relevant segment
    {
        if(type==0)
            return ret(tree[node].p,1);
        else
            return ret(tree[node].ng,1);
    }


    ll left=node*2;
    ll right=(node*2)+1;

    ll mid=(b+e)/2;


    ret x,y;
    if(type==0)
    {
        x=query(left,b,mid,i,j,0);

        if(x.v==1e16)
        {
            x.v=0;
            y=query(right,mid+1,e,i,j,0);

            if(y.v==1e16)
                y.v=0;
        }
        else
        {
            if(x.len%2==0)
                y=query(right,mid+1,e,i,j,0);
            else
                y=query(right,mid+1,e,i,j,1);

            if(y.v==1e16)
                y.v=0;
        }






    }
    else
    {
        x=query(left,b,mid,i,j,1);

        if(x.v==1e16)
        {
            x.v=0;
            y=query(right,mid+1,e,i,j,1);

            if(y.v==1e16)
                y.v=0;
        }
        else
        {

            if(x.len%2==0)
                y=query(right,mid+1,e,i,j,1);
            else
                y=query(right,mid+1,e,i,j,0);

            if(y.v==1e16)
                y.v=0;

        }
    }


    //cout<<node<<" ** "<<x<<" "<<y<<endl;



    return ret(x.v+y.v,x.len+y.len);
}


void update(ll node,ll b,ll e,ll i,ll value)
{
    if(i>e || i<b)                 ///outside segment
        return;

    if(i<=b && e<=i)              ///relevant segment
    {
        tree[node].p=value;
        tree[node].ng=-value;
        return;
    }

    ll left=node*2;
    ll right=(node*2)+1;

    ll mid=(b+e)/2;

    update(left,b,mid,i,value);
    update(right,mid+1,e,i,value);

    if((mid-b+1)%2==0)
    {
        tree[node].p=tree[left].p+tree[right].p;
        tree[node].ng=tree[left].ng+tree[right].ng;
    }
    else
    {
        tree[node].p=tree[left].p+tree[right].ng;
        tree[node].ng=tree[left].ng+tree[right].p;
    }

}



int main()
{
    faster

    ll n,m,t;
    cin>>n;

    for(ll i=1; i<=n; i++)
        cin>>a[i];

    seg(1,1,n);


    ll l,r;

    cin>>m;

    while(m--)
    {
        cin>>t;

        if(t==0)
        {
            cin>>l>>r;
            update(1,1,n,l,r);
        }
        else
        {
            cin>>l>>r;
            ret z=query(1,1,n,l,r,0);
            cout<<z.v<<endl;
        }
    }








    return 0;
}



