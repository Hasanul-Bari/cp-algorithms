#include<bits/stdc++.h>
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define pb push_back
const double PI = acos(-1.0);
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main()
{
    faster

    int n,x;
    cin>>n;

    ordered_set s;

    while(n--)
    {
        cin>>x;
        s.insert(x);
    }

    cout<<*s.find_by_order(2)<<endl;    ///returns an iterator to the k-th largest element (counting from zero),

    cout<<s.order_of_key(3)<<endl;      ///the number of items in a set that are strictly smaller than our item




    return 0;
}
