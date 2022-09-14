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
    struct node *n=new struct node;
    n->data=d;
    n->left=n->right=NULL;
    return n;
}

void printTree(struct node *root)
{
    if(root==NULL)
    return ;
    printTree(root->left);
    cout<<root->data<<" ";
    printTree(root->right);
}

int maxPathSumBtwLeafNodes(struct node *root,int &max_sum)
{
    if(root==NULL)
    return 0;
    int l=maxPathSumBtwLeafNodes(root->left,max_sum);
    int r=maxPathSumBtwLeafNodes(root->right,max_sum);
    if(root->left==NULL)
    return l+root->data;
    if(root->right==NULL)
    return r+root->data;
    max_sum=max(max_sum,l+r+root->data);
    return max(l,r)+root->data;
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
    printTree(root);
    cout<<endl;
    int sum=INT_MIN;
    maxPathSumBtwLeafNodes(root,sum);
    cout<<sum<<endl;
    return 0;
}