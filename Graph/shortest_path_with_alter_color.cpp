#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<pair<int,int> > > &adj,int s,int d,vector<pair<int,int> > &r)
{
    vector<int> ans;
    vector<vector<int>> vis(adj.size(),vector<int>(2,-1));
    vis[0]={0,0};
    queue<pair<int,int> > q;
    q.push({0,1});
    q.push({0,2});
    int cc=0;
    while(!q.empty())
    {
        int u=q.front().first;
        int c1=q.front().second;
        q.pop();
        for(auto v:adj[u])
        {
            int des=v.first;
            int color=v.second;
          //  cout<<des<<" "<<color<<endl;
            if(vis[des][color-1]!=-1 || color==c1)
            continue;
            vis[des][color-1]=1+vis[u][c1];
            q.push({des,color});
            r.push_back({des,color});
            
        }
       // cout<<"next round\n";
    }
    for(auto x:vis)
    {
       sort(x.begin(),x.end());
       int r=x[0]!=-1?x[0]:x[1];
       ans.push_back(r);
    }
    return ans;
}

int main()
{
    int n,re,be,i,u,v;
    cin>>n;
    vector<vector<int> > redEdg,blueEdg;
    cin>>re>>be;
    while(re--)
    {
        cin>>u>>v;
        redEdg.push_back({u,v});
    }
    while(be--)
    {
        cin>>u>>v;
        blueEdg.push_back({u,v});
    }
    //1-->red 2-->blue
    vector<vector<pair<int,int> > > adj_lis(n);
    for(i=0;i<redEdg.size();i++)
    {
        adj_lis[redEdg[i][0]].push_back({redEdg[i][1],1});
    } 
    for(i=0;i<blueEdg.size();i++)
    {
        adj_lis[blueEdg[i][0]].push_back({blueEdg[i][1],2});
    } 
    for(i=0;i<n;i++)
    {
        cout<<i<<" ->";
        for(auto v:adj_lis[i])
        {
            cout<<v.first<<", "<<v.second<<"), ";
        }
        cout<<endl;
    }
    vector<pair<int,int> > rut;
    vector<int> res=bfs(adj_lis,0,i,rut);
       // cout<<rut.size()<<endl;
        // cout<<"-1\n";
        for(int j=0;j<res.size();j++)
        cout<<res[j]<<" ";
        cout<<endl;
    
return 0;



}