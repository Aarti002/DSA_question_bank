#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
//repitation of same element allowed
void allCombinations(vector<int> &v,int i,int n,int sum,vector<int> &ans,set<vector<int> > &res)
{
    if(i==n){
    if(sum==0)
        res.insert(ans);
    return ;
    
    }
   if(v[i]<=sum){
        ans.push_back(v[i]);
        //sum-=v[i];
        allCombinations(v,i,n,sum-v[i],ans,res);
        ans.pop_back();
    }
    allCombinations(v,i+1,n,sum,ans,res);
    
}

int main()
{
    int n,i,sum;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    int cnt=0;
    cin>>sum;
 //   int pp=noOfPartition(s,0,s.length()-1,cnt);
  //  cout<<pp<<endl;
  set<vector<int> > res;
  vector<int> ans;
  allCombinations(v,0,n,sum,ans,res);
  set<vector<int> > ::iterator it;
  for(it=res.begin();it!=res.end();it++)
  {
    vector<int> t=*it;
      for(int j=0;j<t.size();j++)
      cout<<t[j]<<" ";
      cout<<endl;
  }
    return 0;
}