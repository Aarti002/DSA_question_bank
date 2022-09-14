#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,i,j;
    cin>>n>>m;
    vector<int> v1(n),v2(m);
    for(i=0;i<n;i++)
    cin>>v1[i];
    for(i=0;i<m;i++)
    cin>>v2[i];
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cout<<(v1[i]&v2[j]);
        }
        cout<<endl;
    }
    return 0;
}