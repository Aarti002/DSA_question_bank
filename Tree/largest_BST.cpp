#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left,*right;
};

struct info{
    int sz;
    int min;
    int max;
    int ans;        //largest bst size
    bool isBST;
};

struct node* newNode(int data)
{
    struct node *n=new struct node;
    n->data=data;
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

int minValue(struct node *root)
{
    if(root==NULL)
    return INT_MAX;
    

    return min(root->data,min(minValue(root->left),minValue(root->right)));
}

int maxValue(struct node *root)
{
    if(root==NULL)
    return -1;
    
    return max(root->data,max(maxValue(root->left),maxValue(root->right)));
}


bool isValidBST(struct node *root)
{
    if(root==NULL)
    return true;
    if(root->left==NULL && root->right==NULL)
    return true;
    if(root->left && maxValue(root->left)<root->data && root->right==NULL && isValidBST(root->left))
    return true;
    if(root->right && minValue(root->right)>root->data && root->left==NULL && isValidBST(root->right))
    return true;
    if(root->data>maxValue(root->left) && root->data<minValue(root->right) && isValidBST(root->left)  && isValidBST(root->right))
    return true;

    return false;
}

int countNode(struct node *root)
{
    if(root==NULL)
    return 0;
    if(root->left==NULL && root->right==NULL)
    return 1;
    int l=countNode(root->left);
    int r=countNode(root->right);
    return l+r+1;
}


// struct info* largestBST(struct node *root)
// {
//     struct info *r1;
//     r1->ans=0;
//     r1->isBST=false;
//     r1->max=10000;
//     r1->min=-1;
//     r1->sz=0;
//     if(root==NULL)
//     return r1;
//     if(root->left==NULL && root->right==NULL){
//         r1->ans=1;
//         r1->isBST=true;
//         r1->max=root->data;
//         r1->min=root->data;
//         r1->sz=1;
//         return r1;
//     }
 
//     struct info *l=largestBST(root->left);
  
//     struct info *r=largestBST(root->right);
//     struct info *res;
//     res->sz=1+l->sz+r->sz;
    
//     if(l->isBST && r->isBST && l->max<root->data && r->min>root->data){
//         res->isBST=true;
//          res->ans=max(l->ans,r->ans)+1;
//         res->max=max(r->max,max(l->max,root->data));
//         res->min=min(l->min,min(r->min,root->data));
//         return res;
//     }
//     res->isBST=false;
//     res->ans=max(l->ans,r->ans);
    
//     return res;
// }

int largestBST(struct node *root)
{
    if(root==NULL)
    return 0;
    if(root->left==NULL && root->right==NULL)
    return 1;
    int l,r;
    if(isValidBST(root)){
    return countNode(root);
    }
   
    return max(largestBST(root->left),largestBST(root->right));
    
}

int main()
{
    int n,i;
    struct node *root=newNode(12);
    root->left=newNode(2);
    root->right=newNode(23);
    root->left->right=newNode(4);
    root->left->left=newNode(1);
    root->left->left->left=newNode(0);
    printTree(root);
    cout<<endl;
    int ans=largestBST(root);
   cout<<ans<<endl;
    //cout<<"Ans:"<<ans->max<<" "<<ans->min<<" "<<ans->sz<<endl;
    return 0;

}