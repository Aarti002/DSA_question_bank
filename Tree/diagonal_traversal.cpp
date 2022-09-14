#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left,*right;
};

struct node* newNode(int data){
    struct node *n=new struct node;
    n->data=data;
    n->left=n->right;
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

void diagonalTraversal(struct node *root)
{
    queue<struct node*> q;
    q.push(root);
    vector<int> ans;
    //as this is diagonal traversal towards right so we will be storing left wala somewhere 
    //ofc in a queue as we will work on node which appear first. so, left wala node store and 
    //and store right wala data as diagonal in right direction

    //similerly if it was a diagonal traversal in left direction we would have store right node and
    //print or store data of left node.
    while(!q.empty())
    {
        struct node *temp=q.front();
        q.pop();
        while(temp)
        {
            if(temp->left)
            q.push(temp->left);
            ans.push_back(temp->data);
            temp=temp->right;
        }
    }
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    
}

int main()
{
    int i;
    struct node *root=newNode(8);
    root->left=newNode(3);
    root->right=newNode(10);
    root->left->left=newNode(1);
    root->left->right=newNode(6);
    root->left->right->left=newNode(4);
    root->left->right->right=newNode(7);
    root->right->right=newNode(14);
    root->right->right->left=newNode(13);
    printTree(root);
    cout<<endl;
    diagonalTraversal(root);
    return 0;

}