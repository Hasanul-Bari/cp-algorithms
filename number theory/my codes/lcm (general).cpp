#include<bits/stdc++.h>
using namespace std;

int lcm(int a,int b)
{
    if(a>b)
        swap(a,b);

    for(int i=b;    ; i=i+b)
    {
        if(i%a==0)
            return i;
    }
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<lcm(a,b)<<endl;
}
