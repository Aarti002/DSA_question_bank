#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <set>
#include <bits/stdc++.h>
using namespace std;

int LCS(vector<int> &t, vector<int> &v, int m, int n)
{
    if (n == m)
        return 1;
    if (n == 0)
        return 0;
    if (m == 0)
        return 0;
    if (v[m - 1] == t[n - 1])
        return 1 + LCS(t, v, m - 1, n - 1);
    else
        return max(LCS(t, v, m - 1, n), LCS(t, v, m, n - 1));
}

int main()
{
    int n, i;
    cin >> n;
    vector<int> v(n);
    for (i = 0; i < n; i++)
        cin >> v[i];
    vector<int> t = v;
    sort(t.begin(), t.end());
    for (i = 0; i < t.size(); i++)
        cout << t[i] << " ";
    int l = LCS(t, v, n, t.size());
    cout << l << endl;
    return 0;
}