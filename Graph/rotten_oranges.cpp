#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

int countDays_bfs(vector<vector<int> > &org,int n,int m)
{
    queue<pair<int,int> > q;
    int i,j,o=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(org[i][j]==2)
            q.push({i,j});
            if(org[i][j]!=0)
            o++;
        }
    }
    int cnt=0,days=0;;
    int dx[]={0,1,0,-1};
    int dy[]={1,0,-1,0};
    while(!q.empty())
    {
        int k=q.size();
        cnt+=k;
        while(k--)
        {
            pair<int,int> pos=q.front();
            q.pop();
            for(i=0;i<4;i++)
            {
                int x=dx[i]+pos.first;
                int y=dy[i]+pos.second;
                if(x<0||x>=n||y<0||y>=m||org[x][y]!=1)
                continue;
                org[x][y]=2;
                q.push({x,y});
            }
            
        }
        if(!q.empty())
        days++;
    }
    if(cnt!=o)
    return -1;
    return days;
}

int main()
{
    int n,m,i,j;
    cin>>n>>m;
    vector<vector<int> > org(n,vector<int>(m));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>org[i][j];
        }
    }
    int days=countDays_bfs(org,n,m);
    cout<<days<<endl;
    return 0;

}