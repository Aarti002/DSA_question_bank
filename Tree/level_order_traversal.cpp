#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct tree{
    int data;
    struct tree *left=NULL,*right=NULL; 
};
struct tree *root=NULL;
struct tree* addNode(struct tree *root,int data,queue<struct tree*> &q)
{
    struct tree *temp;
    temp=(struct tree*)malloc(sizeof(struct tree));
    temp->data=data;
    temp->left=temp->right=NULL;
    if(root==NULL)
    root=temp;
    else if(q.front()->left==NULL)
        q.front()->left=temp;
    else{
        q.front()->right=temp;
        q.pop();
    }
    q.push(temp);
       
    return root;
}

struct tree* constructTree(struct tree *root,vector<int> &d)
{
    int i;
    queue<struct tree*> q;
    for(i=0;i<d.size();i++)
    {
        root=addNode(root,d[i],q);
    }
    return root;
}

void printTree_inorder(struct tree *root)
{
    if(root==NULL)
    return ;
    cout<<root->data<<" ";
    printTree_inorder(root->left);
    printTree_inorder(root->right);
}

int height(struct tree *root)
{
    if(root==NULL)
    return 0;
    int l=height(root->left);
    int r=height(root->right);
    return 1+max(r,l);
}

void level_order_traversal(struct tree *root,int l,vector<int> &level)
{
    if(root==NULL)
    return ;
    else if(l==1){
    level.push_back(root->data);
   // cout<<root->data<<" ";
   }
    else 
    {
        level_order_traversal(root->left,l-1,level);
        level_order_traversal(root->right,l-1,level);
    }
}

vector<int> printLOT(struct tree *root)
{
    int h=height(root);
    vector<int> right;
    for(int i=1;i<=h;i++)
    {vector<int> level;
        level_order_traversal(root,i,level);
        right.push_back(level[level.size()-1]);
        cout<<endl;
    }
    return right;
}

vector<vector<int> > zigZagTraversal(struct tree *root){
    vector<vector<int> > res;
    int h=height(root);
    for(int i=1;i<=h;i++)
    {
        vector<int> l;
        level_order_traversal(root,i,l);
        if(i%2==0)
        {reverse(l.begin(),l.end());}
        
        res.push_back(l);
    }
    return res;
}

int main()
{
    int n,i,j;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    
    root=constructTree(root,v);
    
    printTree_inorder(root);
    cout<<endl;
    vector<int> r=printLOT(root);
    cout<<"Right view of tree:";
    for(i=0;i<r.size();i++)
    cout<<r[i]<<" ";
    cout<<endl;
    vector<vector<int> > ans=zigZagTraversal(root);
    for(i=0;i<ans.size();i++)
    {
        for(j=0;j<ans[i].size();j++)
        cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}