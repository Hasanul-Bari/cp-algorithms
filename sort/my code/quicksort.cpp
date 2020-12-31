#include<bits/stdc++.h>
using namespace std;

int partition(int a[],int low,int high)
{
    int  pivot=a[low];
    int i=low;
    int j=high+1;

    while(i<j)
    {
        do
        {
            i++;
        }
        while(pivot>=a[i]);


        do
        {
            j--;
        }
        while(pivot<a[j]);


        if(i<j)
            swap(a[i],a[j]);
    }

    swap(a[low],a[j]);

    return j;

}

void quicksort(int a[],int low,int high)
{
    if(low<high)
    {
        int p=partition(a,low,high);

        quicksort(a,low,p-1);
        quicksort(a,p+1,high);
    }
}

int main()
{

    int n;
    cout<<"Enter the size of the array\n";
    cin>>n;
    int a[n];
    cout<<"Enter the elements\n";
    for(int i=0; i<n; i++)
        cin>>a[i];

    quicksort(a,0,n-1);

    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";

    return 0;
}

