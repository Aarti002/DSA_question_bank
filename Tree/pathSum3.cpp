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
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
}

//we need to count all those path which has total equals to sum condn is it should be in
//downward direction and not nessecary that it should include root node or leaf node

//we have two situations either we include root node value or exclude it, if we want to include 
//we will call different function for it

int allPaths(struct node *root,int sum)
{
    if(root==NULL)
    return 0;
    int res=0;
    if(root->data==sum)
    res++;
    res+=allPaths(root->left,sum-root->data)+
    allPaths(root->right,sum-root->data);
    return res;
}

int pathCount(struct node *root,int sum)
{
    if(root==NULL)
    return 0;
    return pathCount(root->left,sum)+
    pathCount(root->right,sum)+
    allPaths(root,sum);

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
    cout<<pathCount(root,7)<<endl;
    return 0;
}