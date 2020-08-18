#include<bits/stdc++.h>
using namespace std;

void countingsort(int a[],int b[],int n,int k)
{
    int c[k+1]={0};
    for(int i=0; i<n; i++)
    {
        c[a[i]]++;
    }

    for(int i=1; i<=k; i++)
    {
        c[i]=c[i]+c[i-1];
    }


    for(int i=n-1; i>=0; i--)
    {
        b[c[a[i]]-1]=a[i];
        c[a[i]]--;
    }

}

int main()
{

    int n;
    cout<<"Enter the size of the array\n";
    cin>>n;
    int a[n];
    cout<<"Enter the elements\n";

    int k=0;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(k<a[i])
            k=a[i];
    }


    int b[n];


    countingsort(a,b,n,k);

    for(int i=0; i<n; i++)
        cout<<b[i]<<" ";

    return 0;

}
