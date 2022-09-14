#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left,*right;
};

struct node* newNode(int data)
{
    struct node *temp=new struct node;
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}

void preOrder(struct node *root,vector<int> &nodes)
{
    if(root==NULL)
    return ;
    cout<<root->data<<" ";
    nodes.push_back(root->data);
    preOrder(root->left,nodes);
    preOrder(root->right,nodes);
}

struct node* LCA(struct node *root,int n1,int n2)
{
    if(root==NULL)
    return NULL;
    if(root->data==n1 || root->data==n2)
    return root;
    struct node *l=LCA(root->left,n1,n2);
    struct node *r=LCA(root->right,n1,n2);
    if(l && r)
    return root;
    if(l)
    return l;
    return r;
}

int distanceFromLCA(struct node *anc,int n)
{
    if(anc==NULL)
    return -1;
    int d=-1;
    if(anc->data==n)
    return d+1;
    
    int ld=distanceFromLCA(anc->left,n);
    int rd=distanceFromLCA(anc->right,n);
    if(ld>=0)
    d=ld+1;
    if(rd>=0)
    d=rd+1;
    return d;

}

int distanceBTWnodes(struct node *root,int n1,int n2)
{
    if(root==NULL)
    return 0;
    //find LCA of nodes
    struct node *lca=LCA(root,n1,n2);
    int d1=distanceFromLCA(lca,n1);
    int d2=distanceFromLCA(lca,n2);
   // cout<<d1<<" "<<d2<<endl;
    return d1+d2;
}

void kConnectedNodes(struct node *root,int target,vector<int> &nodes,int k)
{
    vector<int> ans;
    for(int i=0;i<nodes.size();i++){
        if(nodes[i]!=target)
        {
            int d=distanceBTWnodes(root,target,nodes[i]);
            if(d==k)
            ans.push_back(nodes[i]);
        }
    }
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
}

int main()
{
    struct node *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    root->left->left->left=newNode(8);
    root->left->left->right=newNode(9);
    root->left->right->left=newNode(10);
    vector<int> nodes;
    preOrder(root,nodes);
    cout<<endl;
    kConnectedNodes(root,2,nodes,2);
  //  distanceBTWnodes(root,4,3);
    return 0;
}

