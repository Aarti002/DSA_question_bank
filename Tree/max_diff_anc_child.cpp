#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


struct node{
    int data;
    struct node *left,*right;
};

struct node* newNode(int data){
    struct node *n=new struct node;
    n->data=data;
    n->left=n->right;
    return n;
}

void printTree(struct node *root,vector<int> &v)
{
    if(root==NULL)
    return ;
    v.push_back(root->data);
    cout<<root->data<<" ";
    printTree(root->left,v);
    printTree(root->right,v);
}

struct node* LCA(struct node *root,int a,int b)
{
    if(root==NULL)
    return NULL;
    if(root->data==a || root->data==b)
    return root;
    struct node *l=LCA(root->left,a,b);
    struct node *r=LCA(root->right,a,b);
    if(l && r)
    return root;
    if(l)
    return l;
    return r;
}

int maxDiffAnsNchild(struct node *root)
{
    queue<struct node*> q;
    q.push(root);
    int ans=INT_MIN;
    while(!q.empty())
    {
        struct node *temp=q.front();
        q.pop();
        if(temp->left){
        int d=temp->data-temp->left->data;
        q.push(temp->left);
        ans=max(ans,d);
        }
        if(temp->right){
        int d=temp->data-temp->right->data;
        q.push(temp->right);
        ans=max(ans,d);
        }
    }
    return ans;
}

int main()
{
    int i;
    struct node *root=newNode(8);
    root->left=newNode(3);
    root->right=newNode(10);
    root->left->left=newNode(1);
    root->left->right=newNode(6);
    root->left->right->left=newNode(4);
    root->left->right->right=newNode(7);
    root->right->right=newNode(14);
    root->right->right->left=newNode(13);
    vector<int> v;
    printTree(root,v);
    cout<<endl;
    int ans=INT_MIN;
    for(i=0;i<v.size();i++)
    {
        for(int j=0;j<v.size();j++)
        {
            if(i!=j){
                struct node *lca=LCA(root,v[i],v[j]);
                if(lca->data==v[i] || lca->data==v[j])
                ans=max(ans,max(lca->data-v[i],lca->data-v[j]));
            }
        }
    }
   // int ans=maxDiffAnsNchild(root);
    cout<<ans<<endl;

    return 0;
}