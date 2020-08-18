#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isprime(int n)
{
    if(n<2)
        return false;

    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)
            return false;
    }

    return true;
}




int main()
{
    int n;
    cout<<"Enter a number : ";
    cin>>n;

    if(isprime(n))
        cout<<"Prime"<<endl;
    else
        cout<<"Not Prime"<<endl;

    return 0;

}
