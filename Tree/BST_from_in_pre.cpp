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

struct node *createBST_pre_in(struct node *root, vector<int> &pre, vector<int> &in, int &ind, int l, int r)
{
    if (ind>=pre.size() || l > r)
        return NULL;
    int indx = l;
    while (pre[ind] != in[indx])
        indx++;
    ind++;
    struct node *n = new struct node;
    n->data = in[indx];
    n->left = n->right = NULL;
    n->left = createBST_pre_in(root, pre, in, ind, l, indx - 1);
    n->right = createBST_pre_in(root, pre, in, ind, indx + 1, r);
    return n;
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

int main()
{
    int n, i;
    cin >> n;
    vector<int> pre(n), in(n);
    for (i = 0; i < n; i++)
        cin >> pre[i];
    for (i = 0; i < n; i++)
        cin >> in[i];
    struct node *root = NULL;
    int ind = 0;
    root = createBST_pre_in(root, pre, in, ind, 0, n - 1);
    printBST(root);

    return 0;
}