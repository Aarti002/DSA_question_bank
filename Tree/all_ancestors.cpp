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

bool allAncestors(struct node *root,int val,vector<int> &ans)
{
    if(root==NULL)
    return false;
    
    if(root->data==val)
    return true;
    if(allAncestors(root->left,val,ans) || allAncestors(root->right,val,ans)){
    ans.push_back(root->data);
    return true;
    }
return false;
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
    vector<int> res;
    cout<<endl;
    allAncestors(root,9,res);
    for(int i=0;i<res.size();i++)
    cout<<res[i]<<" ";
    return 0;

}