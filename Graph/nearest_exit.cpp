#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
//very similer to rotten oranges problem
//is this problem we were asked to find minimum no. of moves or steps to exit from the matrix
int minPathToExit(vector<vector<int> > &mat,int x,int y)
{
    queue<pair<int,int> > q;
    q.push({x,y});
    int moves=1;
    vector<pair<int,int> > dir={{0,1},{0,-1},{1,0},{-1,0}};
    mat[x][y]=1;
    while(!q.empty())
    {
        int sz=q.size();
        for(int i=0;i<sz;i++)
        {
            pair<int,int> coor=q.front();
            q.pop();
            for(int j=0;j<4;j++)
            {
                int x1=coor.first+dir[j].first;
                int y1=coor.second+dir[j].second;
                if(x1>=mat.size() || y1>=mat[0].size() || x1<0 || y1<0 || mat[x1][y1]==1)
                continue;
                if((x1==mat.size()-1 || x1==0) || (y1==0 || y1==mat[0].size()-1))
                return moves;
                mat[x1][y1]=1;
                q.push({x1,y1});
            }
        }
        moves++;
    }
    return -1;
    
}

int main()
{
    int n,m,i,j,x,y;
    cin>>n>>m;
    vector<vector<int> > mat(n,vector<int>(m));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        cin>>mat[i][j];
    }
    cin>>x>>y;
    queue<pair<int,int> > q;
    
    int cnt=0;
    int a=minPathToExit(mat,x,y);
    cout<<a<<endl;
    return 0;


}