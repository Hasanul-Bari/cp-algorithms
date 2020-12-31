#include<bits/stdc++.h>>
using namespace std;

int binarysearch(int a[],int n,int item)
{
    int beg=0, end=n-1,mid,ans=-1;

    while(beg<=end)
    {
        mid=(beg+end)/2;
        //cout<<mid<<" "<<beg<<" "<<end<<endl;

        if(item==a[mid])
        {
            ans=mid;
            break;
        }
        else if(item<a[mid])
            end=mid-1;

        else
            beg=mid+1;


    }
    //cout<<mid<<endl;

    return ans;
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

    cout<<binarysearch(a,n,item);



    return 0;

}
/*
10
1 1 2 2 2 2 2 2 2 3
*/

