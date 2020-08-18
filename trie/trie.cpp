#include<bits/stdc++.h>
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define pb push_back
const double PI = acos(-1.0);
using namespace std;


class node{
public:
    bool endmark;
    node *next[26];

    node()
    {
        endmark=false;
        for(int i=0; i<26; i++)
            next[i]=NULL;
    }

    void insert(string s)
    {
        node *curr=this;

        for(int i=0; i<s.length(); i++)
        {
            int id=s[i]-'a';

            if(curr->next[id]==NULL)
            {
                curr->next[id]=new node();
            }

            curr=curr->next[id];
        }

        curr->endmark=true;
    }

    bool search(string s)
    {
        node *curr=this;

        for(int i=0; i<s.length(); i++)
        {
            int id=s[i]-'a';

            if(curr->next[id]==NULL)
            {
                return false;
            }

            curr=curr->next[id];
        }

        return curr->endmark;
    }

    ///clear memory space
    void del()
    {
        for(int i=0; i<10; i++)
        {
            if(next[i]!=NULL)
            {
                next[i]->del();
                delete next[i];
            }
        }
    }


};




int main()
{
    faster

    node *root=new node;

    int n;
    string s;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>s;
        root->insert(s);
    }

    cout<<"Search"<<endl;

    while(cin>>s)
    {
        cout<<root->search(s)<<endl;
    }

    root->del();
    delete root;


    return 0;
}
