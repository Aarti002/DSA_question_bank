#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int min_element(vector<int> &v, int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        int m = i + (j - i) / 2;
        if (v[m] == v[j])
            j--;
        else if (v[m] > v[j])
            i = m + 1;
        else
            j = m;
    }
    return v[j];
}

int main()
{
    int n, i;
    cin >> n;
    vector<int> v(n);
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int min = min_element(v, n);
    cout << min << endl;
    return 0;
}