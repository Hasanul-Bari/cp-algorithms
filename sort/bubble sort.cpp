#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the size of array = ";
    cin>>n;
    int p[n];
    cout<<"Enter "<<n<<" elements"<<endl;

    for(int i=0; i<n; i++)
    {
        cin>>p[i];
    }

    for(int i=1; i<n; i++)
        for(int j=0; j<n-i; j++)
            if(p[j+1]>p[j])
                swap(p[j+1],p[j]);


    cout<<"The sorted array is"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<p[i]<<"\t";
    }

    return 0;

}
