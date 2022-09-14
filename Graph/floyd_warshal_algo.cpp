#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define INT_MAX 9999

void floyd_warshal_algo(vector<vector<int>> &adj_mat, int v)
{

    int i, j, k; 
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            for (k = 0; k < v; k++)
            {
                if ((adj_mat[j][i] + adj_mat[i][k]) < adj_mat[j][k])
                    adj_mat[j][k] = adj_mat[j][i] + adj_mat[i][k];
            }
        }
    }
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            if (adj_mat[i][j] == INT_MAX)
                cout << "INT ";
            else
                cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int e, n, i, j, k, w;
    char x, y;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;
    vector<vector<int>> adj_mat(n, vector<int>(n));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
                adj_mat[i][j] = 0;
            else
                adj_mat[i][j] = INT_MAX;
        }
    }
    cout << "Enter source and destination with edge weight: ";
    while (e--)
    {
        cin >> x >> y >> w;
        adj_mat[x - 'a'][y - 'a'] = w;
        //cout<<x-'a'<<" "<<y-'a'<<endl;
        adj_mat[y - 'a'][x - 'a'] = w;
    }

    floyd_warshal_algo(adj_mat, n);

    return 0;
}