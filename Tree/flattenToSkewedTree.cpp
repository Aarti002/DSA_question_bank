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
    n->right=n->left=NULL;
    return n;
}

void printTree(struct node *root)
{
    if(root==NULL)
    return ;
    // printTree(root->left);
     cout<<root->data<<" ";
    printTree(root->right);
}

void flattenToSkewed(struct node *root,int ord,struct node *start,struct node *prev)
{
    if(root==NULL)
    return ;

    if(ord)
    flattenToSkewed(root->right,ord,start,prev);
    else
    flattenToSkewed(root->left,ord,start,prev);
    struct node *rootl=root->left;
    struct node *rootr=root->right;
    if(start==NULL)
    {
        start=root;
        start->left=NULL;
        prev=root;
    }
    else{
        prev->right=root;
        prev->left=NULL;
        prev=root;

    }
    if(ord)
    flattenToSkewed(rootl,ord,start,prev);
    else
    flattenToSkewed(rootr,ord,start,prev);
}

int main()
{
    int n,i;
    struct node *root=newNode(5);
    root->left=newNode(3);
    root->right=newNode(6);
    //printTree(root);
    struct node *start=NULL,*prev=NULL;
    flattenToSkewed(root,0,start,prev);
    cout<<endl;
    printTree(root);
    return 0;
}