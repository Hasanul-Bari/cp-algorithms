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
    ll prop,sum;
};


int a[10000];
info tree[30000];

void seg(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].sum=a[b];
        return;
    }

    int left=node*2;
    int right=(node*2)+1;

    int mid=(b+e)/2;

    seg(left,b,mid);
    seg(right,mid+1,e);

    tree[node].sum=tree[left].sum+tree[right].sum;
}

int query(int node,int b,int e,int i,int j,int carry=0)
{
    if(i>e || j<b)
        return 0;   ///outside segment

    if(i<=b && e<=j)              ///relevant segment
        return tree[node].sum+(carry*(e-b+1));

    int left=node*2;
    int right=(node*2)+1;

    int mid=(b+e)/2;

    int x=query(left,b,mid,i,j, carry+tree[node].prop);
    int y=query(right,mid+1,e,i,j, carry+tree[node].prop);

    return x+y;
}


void update(int node,int b,int e,int i,int j,int value)
{
    if(i>e || j<b)                 ///outside segment
        return;

    if(i<=b && e<=j)              ///relevant segment
    {
        tree[node].sum=tree[node].sum +  ( (e-b+1)*value);
        tree[node].prop=tree[node].prop + value;
        return;
    }

    int left=node*2;
    int right=(node*2)+1;

    int mid=(b+e)/2;

    update(left,b,mid,i,j,value);
    update(right,mid+1,e,i,j,value);

    tree[node].sum=tree[left].sum+tree[right].sum;


}



int main()
{
    faster

    int n;
    cin>>n;

    for(int i=1; i<=n; i++)
        cin>>a[i];

    seg(1,1,n);


    cout<<query(1,1,n,2,4)<<endl;


    update(1,1,n,2,2,0);
    cout<<query(1,1,n,2,4)<<endl;


    update(1,1,n,2,2,2);
    cout<<query(1,1,n,2,4)<<endl;




    return 0;
}




/*
7
4 -9 3 7 1 0 2
*/

