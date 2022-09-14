#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int maxPathSum(vector<vector<int> > &mat,int row,int col,int n,int m,vector<int> &dp)
{
    if(col<0 || col>=m || row>=n)
    return 0;
    dp[row]=mat[row][col]+max(maxPathSum(mat,row+1,col,n,m,dp),max(maxPathSum(mat,row+1,col+1,n,m,dp),maxPathSum(mat,row+1,col-1,n,m,dp)));
    return dp[row];
}

int main(){
    int n,m,i,j;
    cin>>n>>m;
    vector<vector<int> > mat(n,vector<int>(m));
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    int ans=-1;
    vector<int> dp(n+1);
    for(i=0;i<m;i++)
    ans=max(maxPathSum(mat,0,i,n,m,dp),ans);
    cout<<ans<<endl;
    return 0;
}