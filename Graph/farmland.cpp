#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int> > &v,int i,int j,int n,int m,vector<vector<int> > &vis,vector<pair<int,int> > &ind)
{
    if(i>=n || i<0 || j>=m || j<0 || vis[i][j] || v[i][j]==0)
    return ;
    vis[i][j]=1;
    v[i][j]=0;
    ind.push_back({i,j});
    dfs(v,i+1,j,n,m,vis,ind);
    dfs(v,i-1,j,n,m,vis,ind);
    dfs(v,i,j+1,n,m,vis,ind);
    dfs(v,i,j-1,n,m,vis,ind);
}

int main()
{
    int n,m,i,j;
    cin>>n>>m;
    vector<vector<int> > mat(n,vector<int>(m));
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    vector<vector<int> > vis(n,vector<int>(m,0));
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(mat[i][j]==1 && vis[i][j]==0){
                vector<pair<int,int> > ind;
                //ind.push_back({i,j});
                dfs(mat,i,j,n,m,vis,ind);
                sort(ind.begin(),ind.end());
                if(ind.size()==1)
                ind.push_back({i,j});
                for(auto x:ind)
                cout<<x.first<<" "<<x.second<<endl;
                cout<<"Next island\n";
                vector<int> ans;
                ans.push_back(ind[0].first);
                ans.push_back(ind[0].second);
                ans.push_back(ind[ind.size()-1].first);
                ans.push_back(ind[ind.size()-1].second);
                for(auto p:ans)
                cout<<p<<" ";
                cout<<endl;
            }
        }
    }
    return 0;
}