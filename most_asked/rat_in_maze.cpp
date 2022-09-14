#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void allPossibleWays(vector<vector<int> > &v,int n,int i,int j,string s,vector<string> &ans,vector<vector<int> > &vis)
{
    if(i==n-1 && j==n-1){
        ans.push_back(s);
    return ;}
    
    if((i+1)<n && vis[i+1][j]==0 && v[i+1][j]==1)
    {
        vis[i][j]=1;
      //  cout<<"D";
        allPossibleWays(v,n,i+1,j,s+'D',ans,vis);
        vis[i][j]=0;
    }
    if((j-1)>=0 && vis[i][j-1]==0 && v[i][j-1]==1)
    {
        vis[i][j]=1;
      // cout<<'L';
        allPossibleWays(v,n,i,j-1,s+'L',ans,vis);
        vis[i][j]=0;
    }
    if((j+1)<n && vis[i][j+1]==0 && v[i][j+1]==1)
    {
        vis[i][j]=1;
       //cout<<'R';
        allPossibleWays(v,n,i,j+1,s+'R',ans,vis);
        vis[i][j]=0;
    }
    if((i-1)>=0 && vis[i-1][j]==0 && v[i-1][j]==1)
    {
        vis[i][j]=1;
     // cout<<'U';
        allPossibleWays(v,n,i-1,j,s+'U',ans,vis);
        vis[i][j]=0;
    }
    //vis[i][j]=0;
}

int main()
{
    int n,i,j;
    cin>>n;
    vector<vector<int> > maze(n,vector<int>(n));
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        cin>>maze[i][j];
    }
    vector<string> ans;
    vector<vector<int> > vis(n,vector<int>(n,0));
    allPossibleWays(maze,n,0,0,"",ans,vis);
    for(i=0;i<ans.size();i++){
        //ans[i].insert(0,ans[i][2*n-2]);
        ans[i]+=ans[i][0];
        ans[i].erase(ans[i].begin());
    cout<<ans[i]<<" ";
    }
    return 0;
}