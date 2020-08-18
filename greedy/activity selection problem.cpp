#include<bits/stdc++.h>
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define pb push_back
const double PI = acos(-1.0);
using namespace std;

class activity
{
public:
    int start,finish,sl_no;
};

bool comparator(activity a1,activity a2)
{
    return a1.finish<a2.finish;
}

int main()
{
    faster

    int n;
    cout<<"Enter the no of activities:"<<endl;
    cin>>n;

    activity a[n];

    for(int i=0; i<n; i++)
    {
        cin>>a[i].start>>a[i].finish;
        a[i].sl_no=i+1;
    }

    sort(a,a+n,comparator);

    /*for(int i=0; i<n; i++)
    {
        cout<<a[i].start<<" -- "<<a[i].finish<<endl;
    }*/

    cout<<"Selected activities are "<<endl;

    cout<<a[0].sl_no<<" ("<<a[0].start<<" "<<a[0].finish<<")"<<endl;
    int k=0;

    for(int i=1; i<n; i++)
    {
        if(a[i].start>=a[k].finish)
        {
            cout<<a[i].sl_no<<" ("<<a[i].start<<" "<<a[i].finish<<")"<<endl;
            k=i;
        }
    }



    return 0;
}

/*
6
5 9
1 2
3 4
0 6
5 7
8 9
*/

/*
11
3 9
6 10
2 14
1 4
3 5
8 11
12 16
0 6
8 12
5 7
5 9
*/
