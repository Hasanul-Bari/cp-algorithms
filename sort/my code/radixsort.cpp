#include<bits/stdc++.h>
using namespace std;

void countingsort(int a[],int n,int k)   //k=digitposition  k=1000 means 4th digit
{
    int b[n];   ///output array
    int c[10]={0};
    for(int i=0; i<n; i++)
    {
        c[(a[i]/k)%10]++;
    }

    for(int i=1; i<10; i++)
    {
        c[i]=c[i]+c[i-1];
    }


    for(int i=n-1; i>=0; i--)
    {
        b[c[(a[i]/k)%10]-1]=a[i];
        c[(a[i]/k)%10]--;
    }

    for(int i=0; i<n; i++)
        a[i]=b[i];

}

void radixsort(int a[],int n,int max)
{

    for(int i=1; max/i>0; i=i*10)
    {
        cout<<i<<endl;
        countingsort(a,n,i);

    }

}

int main()
{

    int n;
    cout<<"Enter the size of the array\n";
    cin>>n;
    int a[n];
    cout<<"Enter the elements\n";

    int max=0;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(max<a[i])
            max=a[i];
    }

    radixsort(a,n,max);


    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";

    return 0;

}

