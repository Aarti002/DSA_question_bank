#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct tree{
int data;
struct tree *left,*right;
};

struct tree* addNode(struct tree *root,int d,queue<struct tree*> &q)
{
    struct tree *temp=(struct tree*)malloc(sizeof(struct tree));
    temp->data=d;
    temp->left=temp->right=NULL;
    if(root==NULL)
    root=temp;
    else if(q.front()->left==NULL)
    q.front()->left=temp;
    else if(q.front()->right==NULL)
    {
        q.front()->right=temp;
        q.pop();
    }
    q.push(temp);
    return root;
}

struct tree* createTree(struct tree *root,vector<int> &v)
{
    queue<struct tree*> q;
   // q.push(root);
    for(int i=0;i<v.size();i++)
    {
        root=addNode(root,v[i],q);
    }
    return root;
}

void postOrder(struct tree *root)
{
    if(root==NULL)
    return ;
    
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

bool areEqual(struct tree *root,struct tree *root1)
{
    if(root==NULL && root1==NULL)
    return true;
    if(root==NULL || root1==NULL)
    return false;
    if(root->data==root1->data)
    return true;
    //if(root->left!=NULL && root1->left!=NULL && root->left->data==root1->left->data)
    //return areEqual(root->left,root1->left);
   // if(root->right!=NULL && root1->right!=NULL && root->right->data==root1->right->data)
  //  return areEqual(root->right,root1->right);
    return root->data==root1->data && areEqual(root->left,root1->left) && areEqual(root->right,root1->right);
}

bool checkEqualSubtree(struct tree *root,struct tree *root1)
{
    if(root==NULL)
    return false;
    if(root1==NULL)
    return true;
    if(areEqual(root,root1))
    return true;
    return checkEqualSubtree(root->left,root1) || checkEqualSubtree(root->right,root1);
}

int main()
{
    int n,i,m;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    struct tree *root=NULL;
    root=createTree(root,v);
    postOrder(root);
    cout<<endl;
    struct tree *root1=NULL;
    cin>>m;
    vector<int> v1(m);
    for(i=0;i<m;i++)
    cin>>v1[i];
    root1=createTree(root1,v1);
    postOrder(root1);
    cout<<endl;
    cout<<"Is second tree is subtree of first tree: "<<checkEqualSubtree(root,root1)<<endl;
    return 0;
}