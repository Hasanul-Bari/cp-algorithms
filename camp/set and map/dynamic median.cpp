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

    int n,x;
    cin>>n;

    int med;

    set<int> l,r;

    for(int i=0; i<n; i++)
    {
        cin>>x;


        if(i==0)
        {
            l.insert(x);
            med=x;
        }
        else
        {
            if(l.size()>r.size())
            {
                if(x<med)
                {
                    r.insert(med);
                    l.erase(med);
                    l.insert(x);
                }
                else
                    r.insert(x);
            }
            else if(l.size()==r.size())
            {
                if(x<=med)
                {
                    l.insert(x);
                }
                else
                {
                    r.insert(x);
                    l.insert(*r.begin());

                    r.erase(r.begin());
                }
            }

            med=*l.rbegin();


        }

        cout<<med<<" median"<<endl;

    }




    return 0;
}
