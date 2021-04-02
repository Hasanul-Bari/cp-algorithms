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

ll query(ll node,ll b,ll e,ll i,ll j)
{
    if(i>e || j<b)
        return 0;   ///outside segment

    if(i<=b && e<=j)              ///relevant segment
        return tree[node];

    ll left=node*2;
    ll right=(node*2)+1;

    ll mid=(b+e)/2;

    ll x=query(left,b,mid,i,j);
    ll y=query(right,mid+1,e,i,j);

    return x+y;
}


void update(ll node,ll b,ll e,ll i,ll value)
{
    if(i>e || i<b)                 ///outside segment
        return;

    if(i<=b && e<=i)              ///relevant segment
    {
        tree[node]=value;
        return;
    }

    ll left=node*2;
    ll right=(node*2)+1;

    ll mid=(b+e)/2;

    update(left,b,mid,i,value);
    update(right,mid+1,e,i,value);

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

    ll l,r;

    while(m--)
    {
        cin>>t;

        if(t==1)
        {
            cin>>l>>r;
            update(1,1,n,l+1,r);
        }
        else
        {
            cin>>l>>r;
            cout<<query(1,1,n,l+1,r)<<endl;
        }
    }








    return 0;
}


