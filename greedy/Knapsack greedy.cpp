#include<bits/stdc++.h>
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
using namespace std;

class item
{
public:
    int weight,profit,itemno;
};

bool comparator(item a,item b)
{
    double r1=(double)a.profit/(double)a.weight;
    double r2=(double)b.profit/(double)b.weight;

    return r1>r2;
}

int main()
{
    faster
    int n,c;
    cin>>n>>c;

    item o[n];

    cout<<"Enter the profit and weight of"<<n<<"items"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>o[i].profit>>o[i].weight;
        o[i].itemno=i+1;

    }

    sort(o,o+n,comparator);

    int ccap=0;
    double cprof=0.0;
    cout<<"Selected items -> profit   weight"<<endl;
    for(int i=0; i<n; i++)
    {

        if(ccap+o[i].weight<=c)
        {
            ccap=ccap+o[i].weight;
            cprof=cprof+(double)o[i].profit;

            cout<<o[i].itemno<<" -> "<<o[i].profit<<" "<<o[i].weight<<endl;
        }
        else
        {
            int rem=c-ccap;
            double remp=( (double)rem* ((double)o[i].profit/(double)o[i].weight)  );
            cprof= cprof+remp;

            cout<<o[i].itemno<<" -> "<<remp<<" "<<rem<<endl;
            break;
        }
    }

    cout<<"Total Profit : "<<cprof<<endl;
    return 0;
}

/*
7 15
10 2
5 3
15 5
7 7
6 1
18 4
3 1

*/
