#include<bits/stdc++.h>
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define pb push_back
const double PI = acos(-1.0);
using namespace std;

ll a[100009];

class dataa
{
public:
    ll mn,cnt;
    dataa()
    {

    }
    dataa(ll x,ll c)
    {
        mn=x;
        cnt=c;
    }


};


dataa tree[400099];

void seg(ll node,ll b,ll e)
{
    if(b==e)
    {
        tree[node].mn=a[b];
        tree[node].cnt=1;

        return;
    }

    ll left=node*2;
    ll right=(node*2)+1;

    ll mid=(b+e)/2;

    seg(left,b,mid);
    seg(right,mid+1,e);

    if(tree[left].mn<tree[right].mn)
    {
        tree[node].mn=tree[left].mn;
        tree[node].cnt=tree[left].cnt;
    }
    else if(tree[left].mn>tree[right].mn)
    {
        tree[node].mn=tree[right].mn;
        tree[node].cnt=tree[right].cnt;
    }
    else
    {
        tree[node].mn=tree[right].mn;
        tree[node].cnt=tree[left].cnt+tree[right].cnt;
    }


}

dataa query(ll node,ll b,ll e,ll i,ll j)
{
    if(i>e || j<b)
        return dataa(1e18,0);   ///outside segment

    if(i<=b && e<=j)              ///relevant segment
        return tree[node];

    ll left=node*2;
    ll right=(node*2)+1;

    ll mid=(b+e)/2;

    dataa x=query(left,b,mid,i,j);
    dataa y=query(right,mid+1,e,i,j);


    if(x.mn<y.mn)
    {
        return dataa(x.mn,x.cnt);
    }
    else if(x.mn>y.mn)
    {
        return dataa(y.mn,y.cnt);
    }
    else
    {
        return dataa(x.mn,x.cnt+y.cnt);

    }

}


void update(ll node,ll b,ll e,ll i,ll value)
{
    //cout<<"Enter "<<b<<" "<<e<<endl;

    if(i>e || i<b)                 ///outside segment
        return;

    if(i<=b && e<=i)              ///relevant segment
    {
        //cout<<"Enter "<<value<<endl;
        tree[node].mn=value;
        tree[node].cnt=1;
        return;
    }

    ll left=node*2;
    ll right=(node*2)+1;

    ll mid=(b+e)/2;

    update(left,b,mid,i,value);
    update(right,mid+1,e,i,value);

    if(tree[left].mn<tree[right].mn)
    {
        tree[node].mn=tree[left].mn;
        tree[node].cnt=tree[left].cnt;
    }
    else if(tree[left].mn>tree[right].mn)
    {
        tree[node].mn=tree[right].mn;
        tree[node].cnt=tree[right].cnt;
    }
    else
    {
        tree[node].mn=tree[right].mn;
        tree[node].cnt=tree[left].cnt+tree[right].cnt;
    }

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
            dataa ans=query(1,1,n,l+1,r);
            cout<<ans.mn<<" "<<ans.cnt<<endl;
        }
    }








    return 0;
}





