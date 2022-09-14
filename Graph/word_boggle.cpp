#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void bfs(queue<pair<int,pair<int,int> > > &q,string s,int n,vector<vector<char> > &w)
{
    vector<vector<int> > vis(n,vector<int>(n,0));
    
    vector<pair<int,int> > dir={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
    while(!q.empty())
    {
        int x=q.front().second.first;
        int y=q.front().second.second;
        int pos=q.front().first;
        if(pos==s.length()-1)
            return ;
        for(int i=0;i<8;i++)
        {
            int dx=x+dir[i].first;
            int dy=y+dir[i].second;
            if(dx<0 || dx>=n || dy<0 || dy>=n || vis[dx][dy] || w[dx][dy]!=s[pos+1])
            continue;
            vis[dx][dy]=1;
            w[dx][dy]='#';
            q.push({pos+1,{dx,dy}});
        }
    }
}

bool isPresent(string s,vector<string> &w)
{
    for(int i=0;i<w.size();i++)
    {
        if(w[i]==s)
        return true;
    }
    return false;
}

void findWords(string s,vector<vector<char> > &v,int N,int M,int i,int j,vector<vector<int> > &vis,vector<string> &res,vector<string> &words)
{
    vis[i][j]=1;
    s+=v[i][j];
    if(isPresent(s,words))
    res.push_back(s);

    for(int x=i-1;x<=i+1 && x<N;x++)
    {
        for(int y=j-1;y<=j+1 && j<M;y++)
        {
            if(x>=0 && y>=0 && vis[x][y]==0)
            findWords(s,v,N,M,x,y,vis,res,words);
        }
    }
    s.erase(s.begin());
    vis[i][j]=0;
}

int main()
{
    int n,i,j,p,q;
    cin>>n;
    vector<string> words(n);
    for(i=0;i<n;i++)
    cin>>words[i];
    cin>>p>>q;
    vector<vector<char> > v(p,vector<char>(q));
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        cin>>v[i][j];
    }
    vector<vector<int> > vis(p,vector<int>(q,0));
    string c="";
    vector<string> res;
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        findWords(c,v,p,q,i,j,vis,res,words);
    }
    
    for(i=0;i<res.size();i++)
    cout<<res[i]<<" ";
    return 0;
}