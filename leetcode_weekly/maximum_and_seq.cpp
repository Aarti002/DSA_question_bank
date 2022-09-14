#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j;
    cin >> n;
    vector<int> v(n);
    for (i = 0; i < n; i++)
        cin >> v[i];
    vector<int> res(32, 0);
    for (j = 0; j < 32; j++)
    {
        for (i = 0; i < n; i++)
        {
            if (((v[i] >> j) & 1) == 1)
            {
                res[j]++;
            }
        }
    }
    for (i = 0; i < 32; i++)
        cout << res[i] << " ";
    cout << endl
         << *max_element(res.begin(), res.end()) << endl;
    return 0;
}