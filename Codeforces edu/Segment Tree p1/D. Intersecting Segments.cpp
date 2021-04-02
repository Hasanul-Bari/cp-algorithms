#include<bits/stdc++.h>
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define pb push_back
const double PI = acos(-1.0);
using namespace std;

ll a[100009];
ll tree[800099];

void seg(ll node,ll b,ll e)
{
    if(b==e)
    {
        tree[node]=0;
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

    ll n;
    cin>>n;

    ll nn=(2*n)+1;

    ll x[nn],anss[n+1];



    for(ll i=1; i<=2*n; i++)
    {
        cin>>x[i];

        if(a[x[i]]==0)
        {
            update(1,1,2*n,i,1);
            a[x[i]]=i;
        }
        else
        {
            ll ans=query(1,1,2*n,a[x[i]],i);
            update(1,1,2*n,a[x[i]],0);

            a[x[i]]=0;

            anss[x[i]]=ans-1;

        }
    }

    seg(1,1,2*n);



    reverse(x+1,x+nn);

    for(ll i=1; i<=2*n; i++)
    {
        //cout<<x[i]<<" *"<<endl;

        if(a[x[i]]==0)
        {
            update(1,1,2*n,i,1);
            a[x[i]]=i;
        }
        else
        {
            ll ans=query(1,1,2*n,a[x[i]],i);
            update(1,1,2*n,a[x[i]],0);

            //cout<<ans-1<<" ** "<<x[i]<<endl;

            anss[x[i]]+=ans-1;

        }
    }




   for(int i=1; i<=n; i++)
   {
        cout<<anss[i]<<" ";
   }
   cout<<endl;







    return 0;
}



