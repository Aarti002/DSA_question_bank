#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int> > &v,int x,int y,int n,int m,int nc,int oc)
{
    if(x<0 || x>=n || y<0 || y>=m || v[x][y]!=oc)
    return ;
    //if(v[x][y]==oc)
    v[x][y]=-oc;
    dfs(v,x+1,y,n,m,nc,oc);
    dfs(v,x-1,y,n,m,nc,oc);
    dfs(v,x,y+1,n,m,nc,oc);
    dfs(v,x,y-1,n,m,nc,oc);
    if(x>0 && x<n-1 && y>0 && y<m-1 && oc==abs(v[x+1][y]) && oc==abs(v[x-1][y]) && oc==abs(v[x][y+1]) && oc==abs(v[x][y-1]))
    v[x][y]=oc;

}

int main()
{
    int n,m,i,j;
    cin>>n>>m;
    vector<vector<int>> p(n,vector<int>(m));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        cin>>p[i][j];
    }
    int r,c,nc;
    cin>>r>>c>>nc;
    int oc=p[r][c];
    dfs(p,r,c,n,m,nc,oc);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(p[i][j]<0)
            p[i][j]=nc;
            cout<<p[i][j]<<" ";
        }
      //  cout<<p[i][j]<<" ";
        cout<<endl;
    }
    return 0;

}