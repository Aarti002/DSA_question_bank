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

int findSum(struct node *root)
{
    if(root==NULL)
    return 0;
    int l=findSum(root->left);
    int r=findSum(root->right);
    int d=root->data;
    return d+l+r;
}

bool isSumTree(struct node *root)
{
    if(root==NULL)
    return true;
    if(root->left==NULL && root->right==NULL)
    return true;
    bool flag=false;
    if(root->data==(findSum(root->left)+findSum(root->right)))
    flag=true;
    return flag&&isSumTree(root->left)&&isSumTree(root->right);
}

int main()
{
    int n,i;
    struct node *root=newNode(10);
    root->left=newNode(2);
    root->right=newNode(8);
    root->left->left=newNode(17);
    root->left->right=newNode(-15);
    root->right->left=newNode(3);
    root->right->right=newNode(5);
    // root->left->left->left=newNode(8);
    // root->right->right->right=newNode(9);
    inorder(root);
    vector<int> res;
    cout<<endl;
   cout<< isSumTree(root)<<endl;
   
    return 0;

}