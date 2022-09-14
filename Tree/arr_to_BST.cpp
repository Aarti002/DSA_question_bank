#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left,*right;
};

struct node* createTree(struct node *root,int data)
{
    struct node *n=new struct node;
    n->data=data;
    n->left=n->right=NULL;
    if(root==NULL)
    root=n;
    else if(data>root->data)
    root->right=createTree(root->right,data);
    else
    root->left=createTree(root->left,data);
    return root;
}

void printBST(struct node *root)
{
    if(root!=NULL)
    {
    cout<<root->data<<" ";
    printBST(root->left);
    printBST(root->right);
    }
}

int main()
{
    int n,i;
    cin>>n;
    vector<int> v(n);
    struct node *root=NULL;
    for(i=0;i<n;i++)
    {
        cin>>v[i];
        root=createTree(root,v[i]);
    }
    printBST(root);
    return 0;

}