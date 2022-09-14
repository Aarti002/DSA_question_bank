#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,x,k;
    cin>>n>>k;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    int kth=0;
    int mx=*max_element(v.begin(),v.end());
    vector<int> notp(mx+1,0);
    for(i=0;i<n;i++)
    notp[v[i]]=1;
    vector<int> res;
    for(i=0;i<=mx;i++)
    {
        if(notp[i]==0)
        res.push_back(i);
    }
    for(i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    
    return 0;
}