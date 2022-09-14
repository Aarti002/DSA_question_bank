#include <stdio.h>
#include <stdlib.h>
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
    nn->right=nn->left=NULL;
    return nn;
}
//so, in this approach we are finding range i.e left most node to right most node and then
//traversing in between

//but we might encounter some error for large trees as we are basically doing traversal breath wise
//there might be the case when we leave some deep node
//thats why as a better approach we should use 'map' as it will store each node according to its
//position in the form of coordinates indexs

void storingNodesinCoordinates(struct node *root,int level,int l,map<int,map<int,vector<int> > > &mp)
{
    if(root!=NULL)
    {
        mp[level][l].push_back(root->data);
        storingNodesinCoordinates(root->left,level-1,l+1,mp);
        storingNodesinCoordinates(root->right,level+1,l+1,mp);
    }
}

void findRange(struct node *root,int *mn,int *mx,int hr)
{
    if(root==NULL)
    return ;
    if(*mn>hr)
    *mn=hr;
    if(*mx<hr)
    *mx=hr;
    findRange(root->left,mn,mx,hr-1);
    findRange(root->right,mn,mx,hr+1);
}

void printVerticalNodes(struct node *root,int level,int l)
{
    if(root==NULL)
    return ;
    if(level==l)
    cout<<root->data<<" ";
    printVerticalNodes(root->left,level,l-1);
    printVerticalNodes(root->right,level,l+1);
}

void verticalTraversal(struct node *root)
{
    int min_r=0,max_r=0;
    findRange(root,&min_r,&max_r,0);
    for(int i=min_r;i<=max_r;i++)
    {
        printVerticalNodes(root,i,0);
        cout<<endl;
    }
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
    verticalTraversal(root);

    cout<<"\nVertical order traversal using map:\n ";
    map<int,map<int,vector<int> > > mp;
    storingNodesinCoordinates(root,0,0,mp);
    for(auto ind1:mp)
    {
        for(auto ind2:ind1.second)
        {
            for(auto ind3:ind2.second)
            cout<<ind3<<" ";
           // cout<<endl;
        }
    }
    cout<<endl;
    return 0;

}