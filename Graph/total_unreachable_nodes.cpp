#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, int n, int i, vector<int> &vis, vector<int> &v)
{
    vis[i] = 1;
    v[i] = 1;
    for (auto x : adj[i])
    {
        if (vis[x] == 0)
            dfs(adj, n, x, vis, v);
    }
}

int main()
{
    int i, j, n, e;
    cin >> n >> e;
    vector<vector<int>> adj(n);
    int u, v;
    while (e--)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n, 0);
    vector<int> pro;
    for (i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            vector<int> v(n, 0);
            dfs(adj, n, i, vis, v);
            pro.push_back(count(v.begin(), v.end(), 1));
        }
    }
    int ans = 0;
    for (i = 0; i < pro.size(); i++)
    {
        int x = pro[i];
        for (j = i + 1; j < pro.size(); j++)
        {
            ans += x * pro[j];
        }
    }
    cout << ans << endl;
    return 0;
}