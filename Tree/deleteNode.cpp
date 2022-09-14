#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

struct node *createTree(struct node *root, int data)
{
    struct node *n = new struct node;
    n->data = data;
    n->left = n->right = NULL;
    if (root == NULL)
        root = n;
    else if (data > root->data)
        root->right = createTree(root->right, data);
    else
        root->left = createTree(root->left, data);
    return root;
}

void printBST(struct node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        printBST(root->left);
        printBST(root->right);
    }
}

struct node *minVal(struct node *root)
{
    // if (root == NULL)
    //     return NULL;
    // root = minVal(root->left);
    while(root->left!=NULL && root!=NULL)
    root=root->left;
    return root;
}

struct node *deleteNode(struct node *root, int data)
{
    if (root == NULL)
        return root;
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else if (data < root->data)
        root->left= deleteNode(root->left, data);
    else
    {
        if(root->left==NULL && root->right==NULL)
        return NULL;
        else if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }    
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        
            struct node *temp = minVal(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        
    }
    return root;
}

int main()
{
    int n, i;
    cin >> n;
    vector<int> v(n);
    struct node *root = NULL;
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
        root = createTree(root, v[i]);
    }
    printBST(root);
    cout<<endl;
    struct node *m=minVal(root);
    cout<<"Min val:"<<m->data<<endl;
    root = deleteNode(root, 4);
    
    printBST(root);
    cout<<endl;
    return 0;
}