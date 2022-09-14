#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct tree{
    int data;
    struct tree *left,*right;
};


struct tree* addNode(struct tree *root,int data,queue<struct tree*> &q)
{
    struct tree *temp=(struct tree*)malloc(sizeof(struct tree));
    temp->data=data;
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

struct tree* createTree(struct tree *root,vector<int> &d)
{
    queue<struct tree*> q;
    for(int i=0;i<d.size();i++)
    {
        root=addNode(root,d[i],q);
    }
    return root;
}

int height(struct tree *root)
{
    if(root==NULL)
    return 0;
    int l=height(root->left);
    int r=height(root->right);
    return max(l,r)+1;
}

void printEachLevel(struct tree *root,int l)
{
    if(root==NULL)
    return ;
    else if(l==1)
    cout<<root->data<<" ";
    else {
        printEachLevel(root->left,l-1);
        printEachLevel(root->right,l-1);
    }
}

void printLOT(struct tree *root)
{
    int h=height(root);
    for(int i=1;i<=h;i++)
    {
        printEachLevel(root,i);
        cout<<endl;
    }
}

bool HasPathSum(struct tree *root,int sum)
{
    if(root==NULL)
    return false;
    if(root->left==NULL && root->right==NULL && sum==0)
    return true;
    bool ans=false;
        if(root->left!=NULL)
        ans=ans|| HasPathSum(root->left,sum-root->left->data);
        if(root->right!=NULL)
        ans=ans|| HasPathSum(root->right,sum-root->right->data);
    
    return ans;
}


int main()
{
    int n,i,x,sum;
    cin>>n;
    vector<int> d(n);
    for(i=0;i<n;i++)
    cin>>d[i];
    struct tree *root=NULL;
    root=createTree(root,d);
    printLOT(root);
    cout<<"Enter path sum: ";
    cin>>sum;
    cout<<HasPathSum(root,sum)<<endl;
    return 0;
}