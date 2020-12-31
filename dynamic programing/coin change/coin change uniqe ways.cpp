#include<bits/stdc++.h>
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define pb push_back
const double PI = acos(-1.0);
using namespace std;

int main()
{
    int n,target;
    cin>>n;
    int coin[n+1];
    for(int i=1; i<=n; i++)
        cin>>coin[i];

    cin>>target;
    int ways[n+1][target+1];

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=target; j++)
        {
            if(i==0 && j==0)
                ways[i][j]=1;

            else if(i==0)
                ways[i][j]=0;

            else if(j-coin[i]<0)
            {
                ways[i][j]=ways[i-1][j];
            }
            else
            {
                ways[i][j]=ways[i-1][j]+ways[i][j-coin[i]];
            }
        }
    }


    cout<<ways[n][target]<<endl;

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=target; j++)
        {
            cout<<ways[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

/*
4
2 5 3 6
10
*/
