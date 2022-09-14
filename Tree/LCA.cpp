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

struct node* LCA(struct node *root,struct node *n1,struct node *n2)
{
    if(root==NULL)
    return NULL;
    if(root==n1 || root==n2)
    return root;
    struct node *lt=LCA(root->left,n1,n2);
    struct node *rt=LCA(root->right,n1,n2);
    if(lt && rt)
    return root;
    if(lt)
    return lt;
    return rt;
}


int main()
{
    struct node *r=newNode(1);
    r->left=newNode(2);
    r->right=newNode(3);
    r->left->left=newNode(4);
    r->left->right=newNode(5);
    r->right->left=newNode(6);
    r->left->left->right=newNode(8);
    r->right->right=newNode(7);

    struct node *res=LCA(r,r->left->left,r->left->left->right);
    cout<<res->data<<endl;
    return 0;
}