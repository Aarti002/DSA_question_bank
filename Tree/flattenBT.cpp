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

void printTree(struct node *root){
    if(root==NULL){
        cout<<" NULL ";
    return ;
    }
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
}

void flattenBT(struct node *root)
{
    if(root==NULL || (root->left==NULL && root->right==NULL))
    return ;
    if(root->left){
        flattenBT(root->left);
        struct node *tempr=root->right;
        root->right=root->left;
        root->left=NULL;
        struct node *tr=root->right;
        while(tr->right!=NULL){
            tr=tr->right;
        }
        tr->right=tempr;
    }
    flattenBT(root->right);
}

int main(){
    struct node *r=newNode(1);
    r->left=newNode(2);
    r->right=newNode(3);
    r->left->left=newNode(4);
    r->left->right=newNode(5);
    r->right->left=newNode(6);
    r->left->left->right=newNode(8);
    r->right->right=newNode(7);
    printTree(r);
    cout<<endl;
    flattenBT(r);
    printTree(r);
    return 0;

}