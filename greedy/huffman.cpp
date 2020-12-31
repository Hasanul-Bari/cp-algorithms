#include<bits/stdc++.h>
#define faster  ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
using namespace std;

class node
{
public:
    int freq;
    char key;
    node *left;
    node *right;
};

class comparator
{

public:
    bool operator()(node *a,node *b)
    {
        return b->freq<a->freq;
    }
};
priority_queue<node *, vector<node *>, comparator>PQ;



node* create_node(char ch, int f)
{
    node *temp=new node;
    temp->freq=f;
    temp->key=ch;

    temp->left=temp->right=NULL;

    return temp;
}

void codes(node *head, string str)
{
    if(head==NULL)
        return;
    if(head->left==NULL && head->right==NULL)
    {
        cout<<head->key<<": "<<str<<endl;
        delete head;
        return;
    }
    codes(head->left,str+"0");
    codes(head->right,str+"1");
}



void huffman(void)
{
    node *tmp, *top1,*top2;
    while(PQ.size()>1)
    {
        top1=PQ.top(); PQ.pop();
        top2=PQ.top(); PQ.pop();
        int a=top1->freq+top2->freq;
        tmp=create_node('\0',a);
        tmp->left=top1;
        tmp->right=top2;
        PQ.push(tmp);
    }
    tmp=PQ.top(); PQ.pop();
    codes(tmp,"");
}


int main()
{
    faster

    int n,f;
    char ch;

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ch>>f;
        node *leaf=create_node(ch,f);
        PQ.push(leaf);
    }

    huffman();

    return 0;
}




