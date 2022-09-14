#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
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

void printTree(struct tree *root)
{
    if(root==NULL)
    return ;
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
}

struct tree* inversion(struct tree *root)
{
    if(root==NULL)
    return NULL;
    struct tree *l=inversion(root->left);
    struct tree *r=inversion(root->right);
    struct tree *temp=root->left;
    root->left=root->right;
    root->right=temp;
    return root;
}

int main()
{
    int n,i,x;
    cout<<"No. of nodes in tree: ";
    cin>>n;
    struct tree *root=NULL;
    vector<int> d;
    cout<<"Enter data: ";
    while(n--){
        cin>>x;
        d.push_back(x);
    }
    root=createTree(root,d);
    printTree(root);
    cout<<endl;
    printLOT(root);
    root=inversion(root);
    cout<<endl;
    printLOT(root);
    return 0;
}