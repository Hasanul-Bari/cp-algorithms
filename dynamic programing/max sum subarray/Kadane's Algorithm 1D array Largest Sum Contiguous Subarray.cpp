#include<bits/stdc++.h>
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define pb push_back
const double PI = acos(-1.0);
using namespace std;

void submaxsum(int a[],int n)
{
    int best_sum=0, current_sum=0;
    int start=0, end=0, s=0;

    for(int i=0; i<n; i++)
    {
        current_sum=current_sum+a[i];

        if(best_sum<current_sum)
        {
            best_sum=current_sum;
            start=s;
            end=i;
        }

        if(current_sum<0)
        {
            s=i+1;
            current_sum=0;
        }
    }

    cout<<best_sum<<endl;
    cout<<start<<" "<<end<<endl;
}



int main()
{
    faster

    int n,s;
    cin>>n;

    int a[n];

    for(int i=0; i<n; i++)
        cin>>a[i];

    submaxsum(a,n);




    return 0;
}
