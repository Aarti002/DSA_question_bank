#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
//here we have to seperate nodes in two different groups such that connected edges don't 
//fall under same group ---> for that we will use the concept of coloring

bool bfs(vector<vector<int> > &edg,int n)
{
    int i,j;
    vector<int> vis(n+1,0);
    vector<int> color(n+1,0);
    queue<int> q;
    for(i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            color[i]=1;
            q.push(i);
            while(!q.empty())
            {
                int sz=q.size();
                while(sz--)
                {
                    int u=q.front();
                    q.pop();
                    if(vis[u])
                    continue;
                    vis[u]=1;
                    for(auto v:edg[u])
                    {
                        if(color[u]==color[v])
                        return false;
                        if(color[u]==1)
                        color[v]=2;
                        else
                        color[v]=1;
                        q.push(v);
                    }
                }
            }
        }
    }
    return true;
}


int main()
{
    int n,e,i,u,v;
    cin>>n>>e;
    vector<vector<int> > edg(n+1);
    vector<int> vis(n+1,0);
    vector<int> color(n+1,0);       //0-> no-color, 1-> red , 2-> blue

    while(e--)
    {
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    cout<<bfs(edg,n)<<endl;
    return 0;
}