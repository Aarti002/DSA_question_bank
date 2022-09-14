#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left,*right;
};

struct node* newNode(int data)
{
    struct node *nn=new struct node;
    nn->data=data;
    nn->left=nn->right=NULL;
    return nn;
}

void bottomView(struct node *root,int hd,int level,map<int,pair<int,int> > &mp)
{
    if(root==NULL)
    return ;
    if(level>=mp[hd].second)
    mp[hd]={root->data,level};
    bottomView(root->left,hd-1,level+1,mp);
    bottomView(root->right,hd+1,level+1,mp);
}

int main()
{
    int n,i;
    struct node *root=NULL;
    root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(12);
    root->right->right=newNode(20);
    root->right->left=newNode(13);
    root->right->right->left=newNode(32);
    map<int,pair<int,int> > mp;
    bottomView(root,0,0,mp);
    vector<int> ans;
    for(auto ind:mp)
    {//cout<<ind.first<<": ";
  //  vector<int> temp=ind.second;
    ans.push_back(ind.second.first);
      
        //cout<<endl;
    }
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    return 0;
}