#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void all_subset_sum(vector<int> &v,int i,int n,vector<int> &ans,vector<int> &res)
{
    if(i==n)
    {
        res.push_back(accumulate(ans.begin(),ans.end(),0));
        return;
    }
    vector<int> o1=ans;
    vector<int> o2=ans;
    o1.push_back(v[i]);
    all_subset_sum(v,i+1,n,o1,res);
    all_subset_sum(v,i+1,n,o2,res);
}

int main()
{
    int n,i;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    vector<int> res;
    vector<int> ans;
    all_subset_sum(v,0,n,ans,res);
    sort(res.begin(),res.end());
    for(i=0;i<res.size();i++)
    {
       
        cout<<res[i]<<" ";
       // cout<<endl;
    }
    return 0;
}