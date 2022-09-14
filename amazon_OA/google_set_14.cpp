#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct info{
    vector<int> val;
    int x;
    int y;
    int sum;
};

void allPaths(vector<vector<int> > &maze,int n,int m,vector<vector<int> > &path,int k)
{

    path.push_back({maze[0][0]});
    queue<info> q;
    vector<int> v;
    q.push({{maze[0][0]},0,0,0});
    while(!q.empty())
    {
        info temp=q.front();
        q.pop();
        if(temp.x==n-1 && temp.y==m-1)
        {
            int s=0;
            for(auto v:temp.val)
            s+=v;
            //cout<<s<<endl;
            if(s%k==0)
            {
                path.push_back({temp.val});
            }
        }
        else if(temp.x==n-1)
        {
            vector<int> t1=temp.val;
            t1.push_back(maze[temp.x][temp.y+1]);
            q.push({t1,temp.x,temp.y+1});
        }
        else if(temp.y==m-1)
        {
            vector<int> t1=temp.val;
            t1.push_back(maze[temp.x+1][temp.y]);
            q.push({t1,temp.x+1,temp.y});
        }
        else{
            vector<int> t1=temp.val;
            t1.push_back(maze[temp.x][temp.y+1]);
            q.push({t1,temp.x,temp.y+1});
            t1.pop_back();
            t1.push_back(maze[temp.x+1][temp.y]);
            q.push({t1,temp.x+1,temp.y});
            
        }

    }
}

int main()
{
    int n,m,i,k,j;
    cin>>n>>m;
    vector<vector<int> > mat(n,vector<int>(m));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        cin>>mat[i][j];
    }
    cin>>k;
    //vector<vector<int> > dp(n,vector<int>(m,0));
    //using BFS
    vector<vector<int> > path;
    allPaths(mat,n,m,path,k);
    for(auto u:path)
    {
        for(auto v:u)
        cout<<v<<" ";
        cout<<endl;
    }
    return 0;

}