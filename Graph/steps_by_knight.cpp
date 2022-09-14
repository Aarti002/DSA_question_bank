#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int bfs(int n,int m,int kx,int ky,int tx,int ty)
{
    vector<vector<int> > vis(n,vector<int>(m,0));
    queue<pair<int,int> > q;
    q.push({kx,ky});
    vis[kx][ky]=1;
    vector<pair<int,int> > steps{{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{-1,-2},{1,-2}};
    vector<pair<int,int> > hor{{0,1},{0,-1}},ver{{1,0},{-1,0}};
    int ans=0;
    while(!q.empty())
    {
        int sz=q.size();
        while(sz--){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(x==tx && y==ty)
        return ans;
        
        for(int i=0;i<8;i++)
        {
            int dx=x+steps[i].first;
            int dy=y+steps[i].second;
            if(dx==tx && dy==ty)
            return ans;
            if(dx>=0 && dx<n && dy>=0 && dy<m && vis[dx][dy]==0)
            {
                vis[dx][dy]=1;
                q.push({dx,dy});
            }
            // if(dx>=0 && dx<n && dy>=0 && dy<m && two_stp[i].first==0)
            // {
            //     for(int j=0;j<2;j++)
            //     {
            //         dx+=ver[j].first;
            //         dy+=ver[j].second;
            //         if(dx>=0 && dx<n && dy>=0 && dy<m && vis[dx][dy]==0)
            //         {
            //             vis[dx][dy]=1;
            //             q.push({dx,dy});
            //         }
            //     }
            // }
            // if(dx>=0 && dx<n && dy>=0 && dy<m && two_stp[i].second==0)
            // {
            //     for(int j=0;j<2;j++)
            //     {
            //         dx+=hor[j].first;
            //         dy+=hor[j].second;
            //         if(dx>=0 && dx<n && dy>=0 && dy<m && vis[dx][dy]==0)
            //         {
            //             vis[dx][dy]=1;
            //             q.push({dx,dy});
            //         }
            //     }
            // }
            
          //  cout<<dx<<" "<<dy<<endl;

        }
        ans++;
        }
    }
    return -1;
}

int main()
{
    int n,m,i,j,kx,ky,tx,ty;
    cin>>n>>m;
    //vector<vector<int> > chess(n,vector<int>(m));
    
    cin>>kx>>ky;
    cin>>tx>>ty;
    cout<<"no of steps: "<<bfs(n,m,kx,ky,tx,ty)<<endl;
    

    return 0;
}