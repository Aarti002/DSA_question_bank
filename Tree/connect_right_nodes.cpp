#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct tree{
int data;
struct tree *left,*right,*rright;

};

struct tree* addNode(struct tree *root,int d,queue<struct tree*> &q)
{
    struct tree *temp=(struct tree*)malloc(sizeof(struct tree));
    temp->data=d;
    temp->left=temp->right=temp->rright=NULL;
    if(root==NULL)
    root=temp;
    else if(q.front()->left==NULL){
    q.front()->left=temp;

    }
    else if(q.front()->right==NULL){
        q.front()->right=temp;
        q.pop();
    }
    q.push(temp);
    return root;
}

struct tree* constructTree(struct tree *root,vector<int> &v)
{
    queue<struct tree*> q;
    for(int i=0;i<v.size();i++)
    {
        root=addNode(root,v[i],q);
    }
    return root;
}

void inorder(struct tree *root)
{
    if(root==NULL)
    return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

struct tree* connectToRight(struct tree *root)
{
    if(root==NULL)
    return NULL;
    queue<struct tree*> q;
    struct tree *prev=NULL;
    q.push(root);

    while(!q.empty())
    {
        int sz=q.size();
        for(int i=0;i<sz;i++){
        struct tree *t=q.front();
        q.pop();
        if(i==sz-1)
        t->rright=NULL;
        else
        t->rright=q.front();
        if(t->left!=NULL)
        q.push(t->left);
        if(t->right!=NULL)
        q.push(t->right);
       
        }
        
    }
    return root;
}

int height(struct tree *root)
{
    if(root==NULL)
    return 0;
    int l=height(root->left);
    int r=height(root->right);
    return 1+max(r,l);
}

struct tree* ConnectedTree(struct tree *root)
{
    queue<struct tree*> q;
    if(root)
    q.push(root);
    struct tree *temp;
    while(!q.empty())
    {
        int sz=q.size();
        for(int i=0;i<sz;i++)
        {
            temp=q.front();
            q.pop();
            cout<<temp->data<<"=>";
            if(i==sz-1)
            temp->rright=NULL;
            else
            temp->rright=q.front();
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
        }
        cout<<"NULL\n";
        
    }
    return root;
}


int main()
{
    int n,i;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    struct tree *root=NULL;
    root=constructTree(root,v);
  //  inorder(root);
    root=ConnectedTree(root);
  //  printConnectedTree(root);
    return 0;

}