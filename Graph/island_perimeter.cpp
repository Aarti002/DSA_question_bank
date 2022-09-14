#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int> > &v,int x,int y,int n,int m)
{
    if(x<0 || x>=n || y<0 || y>=m )
    return 1;
    
    if(v[x][y]==-1)
    return 0;
    if(v[x][y]==0)
    return 1;
    v[x][y]=-1;
    int sur=0;
    sur+=dfs(v,x+1,y,n,m);
    sur+=dfs(v,x-1,y,n,m);
    sur+=dfs(v,x,y+1,n,m);
    sur+=dfs(v,x,y-1,n,m);
    return sur;

}

int main()
{
    int n,m,i,j;
    cin>>n>>m;
    vector<vector<int> > v(n,vector<int>(m));
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
        cin>>v[i][j];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(v[i][j]==1)
            {
                int sur=0;
                
                cout<<dfs(v,i,j,n,m)<<endl;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        cout<<v[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
