#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,u,v,e,i;
    cin>>n>>e;
    vector<vector<int> > edg(n),revedg(n);
    while(e--)
    {
        cin>>u>>v;
        edg[u].push_back(v);
        revedg[v].push_back(u);
    }
    int ans=0;
    vector<int> vis(n,0);
    
    queue<int> q;
    q.push(0);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=1;
        for(auto v:edg[u])
        {
            if(vis[v]==1)
            continue;
            q.push(v);
            ans++;
        }
        for(auto v:revedg[u])
        {
            if(vis[v]==1)
            continue;
            q.push(v);
            //ans++;
        }

    }
    // int ans=0;
    // for(i=0;i<edg[0].size();i++)
    // ans+=edg[edg[0][i]].size();
    // ans+=edg[0].size();
    cout<<ans<<endl;
    return 0;

}