#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left,*right;
};

struct node* newNode(int data){
    struct node *n=new struct node;
    n->data=data;
    n->left=n->right=NULL;
    return n;
}

void traverseTopView(struct node *root,int l,int hr,map<int,pair<int,int>> &mp)
{
    if(root==NULL)
    return ;
    if (mp.count(hr) == 0) {
        mp[hr] = make_pair(root->data, l);
    }
    else if (mp[hr].second > l) {
        mp[hr] = make_pair(root->data, l);
    }
    traverseTopView(root->left,l+1,hr-1,mp);
    traverseTopView(root->right,l+1,hr+1,mp);
}

void topView(struct node *root){
    map<int,pair<int,int> > mp;
    traverseTopView(root,0,0,mp);
    for(auto &x:mp){
        cout<<x.second.first<<" ";
    }
    
}

void printTree(struct node *root){
    if(root==NULL)
    return ;
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
}

int main()
{
    int i,n;
    struct node *root=NULL;
    root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(12);
    root->right->right=newNode(20);
    root->right->right->left=newNode(32);
    topView(root);

    
    cout<<endl;
    return 0;
}