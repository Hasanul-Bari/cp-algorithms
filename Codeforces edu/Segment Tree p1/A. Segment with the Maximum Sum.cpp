#include<bits/stdc++.h>
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define pb push_back
const double PI = acos(-1.0);
using namespace std;


class info
{
public:
    ll sum,pref,suff,ans;
};



ll a[100009];
info tree[400099];


void seg(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].sum=a[b];
        tree[node].pref=a[b];
        tree[node].suff=a[b];
        tree[node].ans=a[b];

        return;
    }

    int left=node*2;
    int right=(node*2)+1;

    int mid=(b+e)/2;

    seg(left,b,mid);
    seg(right,mid+1,e);

    tree[node].sum=tree[left].sum+tree[right].sum;
    tree[node].pref=max(tree[left].pref, tree[left].sum+tree[right].pref);
    tree[node].suff=max(tree[right].suff, tree[right].sum+tree[left].suff);

    tree[node].ans =max( max(tree[left].ans,tree[right].ans), tree[left].suff+tree[right].pref);
}

info query(int node,int b,int e,int i,int j)
{


    if(i>e || j<b)         ///outside segment
    {
        info z;

        z.sum=0;
        z.pref=INT_MIN;
        z.suff=INT_MIN;
        z.ans=INT_MIN;

        return z;


    }

    if(i<=b && e<=j)              ///relevant segment
    {

        return tree[node];
    }

    int left=node*2;
    int right=(node*2)+1;

    int mid=(b+e)/2;

    info l=query(left,b,mid,i,j);
    info r=query(right,mid+1,e,i,j);


    info z;

    z.sum=l.sum+r.sum;
    z.pref=max(l.pref, l.sum+r.pref);
    z.suff=max(r.suff, r.sum+l.suff);

    z.ans =max( max(l.ans,r.ans), l.suff+r.pref);


    return z;
}


void update(int node,int b,int e,int i,ll value)
{
    if(i>e || i<b)                 ///outside segment
        return;
    if(i<=b && e<=i)              ///relevant segment
    {
        tree[node].sum=value;
        tree[node].pref=value;
        tree[node].suff=value;
        tree[node].ans=value;
        return;
    }

    int left=node*2;
    int right=(node*2)+1;
    int mid=(b+e)/2;

    update(left,b,mid,i,value);
    update(right,mid+1,e,i,value);


    tree[node].sum=tree[left].sum+tree[right].sum;
    tree[node].pref=max(tree[left].pref, tree[left].sum+tree[right].pref);
    tree[node].suff=max(tree[right].suff, tree[right].sum+tree[left].suff);

    tree[node].ans =max( max(tree[left].ans,tree[right].ans), tree[left].suff+tree[right].pref);
}



int main()
{
    faster

    ll n,m,x,y,t;


    cin>>n>>m;

    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }


    seg(1,1,n);

    info z;
    z=query(1,1,n,1,n);
    if(z.ans<0)
        z.ans=0;

    cout<<z.ans<<endl;

    while(m--)
    {
        cin>>x>>y;

        update(1,1,n,x+1,y);


        z=query(1,1,n,1,n);

        if(z.ans<0)
            z.ans=0;

        cout<<z.ans<<endl;
        //cout<<mx<<endl;

        /*for(int i=1; i<=4*n; i++)
            cout<<tree[i]<<" ";
        cout<<endl;*/

    }


    return 0;
}




