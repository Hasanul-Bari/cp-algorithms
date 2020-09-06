#include<bits/stdc++.h>
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define pb push_back
const double PI = acos(-1.0);
using namespace std;

char b[1000][1000];

void print_lcs(string x,int i,int j)
{
    if(i==0 || j==0)
        return;

    else if(b[i][j]=='C')
    {
        print_lcs(x,i-1,j-1);
        cout<<x[i-1];
    }
    else if(b[i][j]=='U')
        print_lcs(x,i-1,j);
    else
        print_lcs(x,i,j-1);
}


void lcs(string x,string y)
{
    int m=x.length(),n=y.length();

    int l[m+1][n+1];


    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0 || j==0)
            {
                l[i][j]=0;
            }
            else if(x[i-1]==y[j-1])
            {
                l[i][j]=l[i-1][j-1]+1;
                b[i][j]='C';
            }
            else if(l[i-1][j]>=l[i][j-1])
            {
                l[i][j]=l[i-1][j];
                b[i][j]='U';
            }
            else
            {
                l[i][j]=l[i][j-1];
                b[i][j]='L';
            }
        }
    }

    cout<<l[m][n]<<endl;

    print_lcs(x,m,n);


    /*for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            cout<<b[i][j];
        }
        cout<<endl;
    }*/
}




int main()
{
    string x,y;
    cin>>x>>y;

    lcs(x,y);


    return 0;
}


/*
BDCABA
ABCBDAB

*/

/*


ABCBDAB
BDCABA

*/
