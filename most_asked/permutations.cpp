#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void allPermutations(vector<int> &v,vector<vector<int> > &res,int n,vector<int> &flag)
{
    if(v.size()==n)
    {
       // v.push_back(ind);
        res.push_back(v);
      //  v.clear();
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(flag[i]==0){
            flag[i]=1;
        v.push_back(i);
        allPermutations(v,res,n,flag);
        v.pop_back();
        flag[i]=0;
        }
    }
    //v.pop_back();
    return ;
}

int main()
{
    int n,i,j;
    cin>>n;
    vector<int> v,flag(n,0);
    vector<vector<int> > res;

    allPermutations(v,res,n,flag);
    for(i=0;i<res.size();i++)
    {
        for(j=0;j<res[i].size();j++)
        cout<<res[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}