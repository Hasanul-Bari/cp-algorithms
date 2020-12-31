#include<bits/stdc++.h>
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define pb push_back
const double PI = acos(-1.0);
using namespace std;

int main()
{
    faster

    int n;
    cin>>n;

    int a[n];

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    sort(a,a+n);

    priority_queue<int > q;

    int c=0,fi=a[n-1];

    q.push(fi);

    //cout<<q.top()<<endl;

    for(int i=n-2; i>=0; i--)
    {
        c=c+q.top();
        q.pop();

        q.push(a[i]);
        q.push(a[i]);
    }

    cout<<c<<endl;







    return 0;
}
