#include<bits/stdc++.h>
using namespace std;

insertionsort(int a[],int n)
{
    for(int i=1; i<n; i++)
    {
        int key=a[i];
        int j=i-1;

        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=a[j];
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

    insertionsort(a,n);

    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";

    return 0;

}
