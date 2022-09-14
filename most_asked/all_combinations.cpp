#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void allCombinations(vector<int> &v,vector<vector<int> > &res,int i,int n,int k)
{
    if(v.size()==k)
    {
        res.push_back(v);
        return ;
    }
    for(int p=i;p<n+1;p++)
    {
        v.push_back(p);
        allCombinations(v,res,p+1,n,k);
        v.pop_back();
    }
    return ;
}

int main()
{
    int n,k,i,j;
    cin>>n>>k;
    vector<vector<int> > res;
    vector<int> v;
    allCombinations(v,res,1,n,k);
    for(i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        cout<<res[i][j]<<" ";
        cout<<endl;
    }
    return 0;

}