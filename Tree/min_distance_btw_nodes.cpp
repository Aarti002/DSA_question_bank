#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left,*right;
};

struct node* newNode(int d)
{
    struct node *nn=new struct node;
    nn->data=d;
    nn->left=nn->right=NULL;
    return nn;
}

void inorder(struct node *root)
{
    if(root==NULL)
    return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
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

int distanceFromLCA(struct node *root,int d)
{
    if(root==NULL)
    return -1;
    int dis=-1;
    if(root->data==d)
    return dis+1;
    int l=distanceFromLCA(root->left,d);
    int r=distanceFromLCA(root->right,d);
   if(l>=0)
   {
       dis=l+1;
     //  return dis;
   }
   if(r>=0)
   {
       dis=r+1;
       //return dis;
   }

   return dis;
}

int main()
{
    int n,i;
    struct node *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    root->left->left->left=newNode(8);
    root->right->right->right=newNode(9);
    inorder(root);
    cout<<endl;
    struct node *lca=LCA(root,8,6);
    int dis=0;
    int d=distanceFromLCA(lca,8);
    int dis1=0;
    int d1=distanceFromLCA(lca,6);
    cout<<lca->data<<endl<<"minimum distance between these nodes:";
    cout<<d+d1<<endl;
  //  cout<<d1<<endl;

    return 0;

}