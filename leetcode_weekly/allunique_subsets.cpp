#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void allUniqueSubsets(vector<int> &v,int i,int n,vector<int> &ans,set<vector<int> > &res)
{
    if(i==n)
    {
        res.insert(ans);
        return;
    }
    vector<int> o1=ans;
    vector<int> o2=ans;
    o1.push_back(v[i]);
    allUniqueSubsets(v,i+1,n,o1,res);
    allUniqueSubsets(v,i+1,n,o2,res);
}

int main()
{
    int n,i;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    sort(v.begin(),v.end());
    vector<int> ans;
    set<vector<int> > res;
    allUniqueSubsets(v,0,n,ans,res);
    //sort(res.begin(),res.end());
    vector<vector<int> > out;
    set<vector<int> > ::iterator it;
    for(it=res.begin();it!=res.end();it++)
    {
        vector<int> t=*it;
        for(i=0;i<t.size();i++)
        cout<<t[i]<<" ";
        cout<<endl;
    }
    return 0;
}