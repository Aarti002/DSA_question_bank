#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct tree{
    int data;
    struct tree *left,*right;
};

struct tree* addNode(struct tree *root,int d,queue<struct tree*> &q){
    struct tree *temp=(struct tree*)malloc(sizeof(struct tree));
    temp->data=d;
    temp->left=temp->right=NULL;
    if(root==NULL)
    root=temp;
    else if(q.front()->left==NULL)
    q.front()->left=temp;
    else if(q.front()->right==NULL)
    {
        q.front()->right=temp;
        q.pop();    
    }
    q.push(temp);
    return root;
}

struct tree* createTree(struct tree *root,vector<int> &v)
{
    queue<struct tree*> q;
    for(int i=0;i<v.size();i++)
    root=addNode(root,v[i],q);
    return root;
}

int height(struct tree *root){
    if(root==NULL)
    return 0;
    int l=height(root->left);
    int r=height(root->right);
    return max(l,r)+1;
}

void eachLevel(struct tree *root,int l)
{
    if(root==NULL)
    return ;
    else if(l==1)
    cout<<root->data<<" ";
    else{
        eachLevel(root->left,l-1);
        eachLevel(root->right,l-1);
    }
}

void LOT(struct tree *root)
{
    int h=height(root);
    for(int i=1;i<=h;i++)
    {
        eachLevel(root,i);
        cout<<endl;
    }
}

bool searchNode(struct tree *root,int d)
{
    if(root==NULL)
    return false;
    if(root->data==d)
    return true;
    if(root->left || root->right)
    return searchNode(root->left,d)||searchNode(root->right,d);
    return false;
}

int main()
{
    int n,i,x;
    cin>>n;
    struct tree *root=NULL;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    root=createTree(root,v);
    cout<<endl;
    LOT(root);
    cin>>x;
    cout<<"Search "<<x<<" in the tree:"<<searchNode(root,x)<<endl;
    return 0;

}