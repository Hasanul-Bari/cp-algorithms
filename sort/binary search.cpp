#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the size of array = ";
    cin>>n;
    int *p=new int [n];
    cout<<"Enter "<<n<<" elements(sorted)"<<endl;

    for(int i=1; i<=n; i++)
    {
        cin>>p[i];
    }

    int item, beg=1, end=n;
    cout<<"Enter the ITEM u want to search = ";
    cin>>item;

    int mid=(int)(beg+end)/2;
    while(beg<=end)
    {
        if(item<p[mid])
            end=mid-1;

        else
            beg=mid+1;

        mid=(int)(beg+end)/2;
    }

    if(p[mid]==item)
        cout<<mid<<endl;

    else
        cout<<"NOT FOUND"<<endl;

    return 0;

}

