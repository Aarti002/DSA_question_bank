#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,i,k,j;
    cin>>n>>m;
    vector<int> v1(n),v2(m);
    for(i=0;i<n;i++)
    cin>>v1[i];
    for(j=0;j<m;j++)
    cin>>v2[j];
    i=0;j=0;
    cin>>k;
    vector<int> ans;
    while(i<n && j<m)
    {
        if(v1[i]<v2[j])
        {
        ans.push_back(v1[i]);
        i++;
        }
        else if(v2[j]<v1[i])
        {
            ans.push_back(v2[j]);
            j++;
        }
        else{
            ans.push_back(v1[i]);
            ans.push_back(v2[j]);
            i++;
            j++;
        }
       
    }
    while(i<n)
    {
        ans.push_back(v1[i]);
        i++;
    }
    while(j<m)
    {
        ans.push_back(v2[j]);
        j++;
    }
    cout<<ans[k-1]<<endl;
    return 0;
}