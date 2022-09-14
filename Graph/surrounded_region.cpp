#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
bool seen=false;

vector<vector<char> > b(100,vector<char> (100));

void mark(vector<vector<char> > &b,int i,int j,int n,int m)
{
    if(i<0 || i>n || j<0 || j>m)
    return ;
    if(b[i][j]=='X')
    return ;
    b[i][j]='0';
    mark(b,i+1,j,n,m);
    mark(b,i,j+1,n,m);
    mark(b,i-1,j,n,m);
    mark(b,i,j-1,n,m);
}

void dfs(vector<vector<char> > &b,int i,int j,int n,int m,vector<vector<int> > &vis)
{
    if(i<0 || i>n || j<0 || j>m)
    return ;
    if(b[i][j]=='X' || vis[i][j])
    return ;
    if(i<=0 || i>=n-1 || j<=0 || j>=m-1)
    seen=true;
    
    vis[i][j]=1;
    dfs(b,i+1,j,n,m,vis);
    dfs(b,i,j+1,n,m,vis);
    dfs(b,i-1,j,n,m,vis);
    dfs(b,i,j-1,n,m,vis);
}

int main()
{
    int n,i,m,j;
    cin>>n>>m;
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        cin>>b[i][j];
    }
    
    vector<vector<int> > vis(n,vector<int>(m,0));
    for(i=1;i<n-1;i++)
    {
        for(j=1;j<m-1;j++)
        {
            if(b[i][j]==0 && !vis[i][j])
            {
                seen=false;
                dfs(b,i,j,n,m,vis);
                if(seen==false)
                mark(b,i,j,n,m);
                seen=true;
            } 
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        cout<<b[i][j]<<" ";
        cout<<endl;
    }
    return 0;

}