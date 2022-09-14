#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void findPath(vector<vector<int> > &v,vector<vector<int> > &vis,int x,int y)
{
    if(x<0 || y>=v[0].size() || x>=v.size() || y<0 || vis[x][y]==1 || v[x][y]==0)
    return ;
    vis[x][y]=1;
    findPath(v,vis,x+1,y);
    findPath(v,vis,x,y+1);
    findPath(v,vis,x,y-1);
    findPath(v,vis,x-1,y);
}

int isPossible(vector<vector<int> > &v,int n,int m)
{
    vector<vector<int> > vis(n,vector<int>(m,0));
    int i,j,sx,sy,ex,ey;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(v[i][j]==1)
            {
                sx=i;
                sy=j;
            }
            if(v[i][j]==2)
            {
                ex=i;
                ey=j;
            }
        }
    }
    findPath(v,vis,sx,sy);
    return vis[ex][ey];
}

int main()
{
    int n,i,m,j;
    cin>>n>>m;
    vector<vector<int> > v(n,vector<int> (m));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        cin>>v[i][j];
    }
    int ans=isPossible(v,n,m);
    cout<<"Is path possible from 1 to 2:"<<(ans==1?"Yes":"No")<<endl;
    return 0;
}