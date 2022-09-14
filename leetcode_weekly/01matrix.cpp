#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int> > &v,vector<vector<int> > &vis,int i,int j,int n,int m,int &cnt)
{
    if(i<0 || i>=n || j<0 || j>=m || vis[i][j]==1)
    return -1;
    if(v[i][j]==0)
    return 0;
    vis[i][j]=1;
    int res= 1+min(dfs(v,vis,i+1,j,n,m,cnt),min(dfs(v,vis,i-1,j,n,m,cnt),min(dfs(v,vis,i,j+1,n,m,cnt),dfs(v,vis,i,j-1,n,m,cnt))));
    vis[i][j]=0;
    return res;
}



int main()
{
    int n,m,i,j;
    cin>>n>>m;
    vector<vector<int> > v(n,vector<int> (m));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        cin>>v[i][j];
    }
    vector<vector<int> > vis(n,vector<int> (m,0));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(v[i][j]==1 && vis[i][j]==0)
            {
                int cnt=0;
                
                cout<<dfs(v,vis,i,j,n,m,cnt)<<" ";
            }
            else
            cout<<0<<" ";
        }
        cout<<endl;
    }
    return 0;

}