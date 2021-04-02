#include<bits/stdc++.h>
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define pb push_back
const double PI = acos(-1.0);
using namespace std;

ll a[100009];
ll tree[400099];

void seg(ll node,ll b,ll e)
{
    if(b==e)
    {
        tree[node]=a[b];
        return;
    }

    ll left=node*2;
    ll right=(node*2)+1;

    ll mid=(b+e)/2;

    seg(left,b,mid);
    seg(right,mid+1,e);

    tree[node]=tree[left]+tree[right];
}

ll query(ll node,ll b,ll e,ll k)
{
    if(b==e)
    {
        return b;
    }

    ll left=node*2;
    ll right=(node*2)+1;

    ll mid=(b+e)/2;


    if(tree[left]>=k)
    {
        return query(left,b,mid,k);
    }
    else
    {
        return query(right,mid+1,e,k-tree[left]);
    }


}


void update(ll node,ll b,ll e,ll i)
{
    if(i>e || i<b)                 ///outside segment
        return;

    if(i<=b && e<=i)              ///relevant segment
    {
        tree[node]=1-tree[node];
        return;
    }

    ll left=node*2;
    ll right=(node*2)+1;

    ll mid=(b+e)/2;

    update(left,b,mid,i);
    update(right,mid+1,e,i);

    tree[node]=tree[left]+tree[right];


}



int main()
{
    faster

    ll n,m,t;
    cin>>n>>m;

    for(ll i=1; i<=n; i++)
        cin>>a[i];

    seg(1,1,n);

    ll l,k;

    while(m--)
    {
        cin>>t;

        if(t==1)
        {
            cin>>l;
            update(1,1,n,l+1);
        }
        else
        {
            cin>>k;
            cout<<query(1,1,n,k+1)-1<<endl;
        }
    }








    return 0;
}



