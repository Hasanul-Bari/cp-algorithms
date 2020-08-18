#include<bits/stdc++.h>
using namespace std;

void merge(int a[],int left,int mid, int right)
{
    int n1=mid-left+1;
    int n2=right-mid;

    int L[n1],R[n2];

    for(int i=0; i<n1; i++)
        L[i]=a[left+i];

    for(int i=0; i<n2; i++)
        R[i]=a[mid+1+i];


    int i=0,j=0,k=left;

    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
        k++;
    }


    while(i<n1)
    {
        a[k]=L[i];
        i++;
        k++;
    }

    while(j<n2)
    {
        a[k]=R[j];
        j++;
        k++;
    }
}

void mergesort(int a[], int left,int right)
{
    if(left<right)
    {
        int mid=(left+right)/2;

        mergesort(a,left,mid);
        mergesort(a,mid+1,right);

        merge(a,left,mid,right);


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


    mergesort(a,0,n-1);

    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";

    return 0;

}



