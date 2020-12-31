#include<bits/stdc++.h>>
using namespace std;

int upperbound(int a[],int n,int item)
{
    int beg=0, end=n,mid;

    while(beg<end)
    {
        mid=(beg+end)/2;
        //cout<<mid<<" "<<beg<<" "<<end<<endl;

        if(item<a[mid])
            end=mid;

        else
            beg=mid+1;


    }

    return beg;
}




int main()
{
    int n;
    cout<<"Enter the size of array = ";
    cin>>n;
    int a[n];
    cout<<"Enter "<<n<<" elements(sorted)"<<endl;

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int item;
    cout<<"Enter the ITEM u want to search = ";
    cin>>item;

    cout<<upperbound(a,n,item)<<endl;
    int i=upper_bound(a,a+n,item)-a;
    cout<<i<<endl;



    return 0;

}
