#include<bits/stdc++.h>
using namespace std;

int w[1000];
int p[1000];

int knapsack(int c, int n)
{
    if(c==0 || n==0)
        return 0;



    if(w[n]>c)
        return knapsack(c,n-1);
    else
        return  max( knapsack(c,n-1),  p[n]+knapsack(c-w[n],n-1));
}


int main()
{
    int n,c;
    cin>>n>>c;


    for(int i=1; i<=n; i++)
        cin>>w[i];

    for(int i=1; i<=n; i++)
        cin>>p[i];

    cout<<knapsack(c,n)<<endl;
}

/*

4 20
5 10 3 12
10 40 50 75

*/
