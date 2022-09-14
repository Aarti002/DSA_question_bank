#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void allSubsets(vector<int> &v,int i,int n,vector<int> &ans,vector<vector<int> > &res)
{
    
        res.push_back(ans);
       
    for(int k=i;k<n;k++){
   ans.push_back(v[k]);
    allSubsets(v,k+1,n,ans,res);
    ans.pop_back();
    }
}

int main()
{
    int n,i;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    vector<vector<int> > res;
    vector<int> ans;
    allSubsets(v,0,n,ans,res);
    for(i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        cout<<res[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}