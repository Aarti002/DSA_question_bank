#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int bfs(vector<int> &move,int n)
{cout<<"in...\n";
    queue<pair<int,int> > q;
    q.push({0,0});
    vector<int> vis(2*n,0);
    int v,d;
    while(!q.empty())
    {cout<<"loop\n";
        v=q.front().first;
        d=q.front().second;
        if(v==n-1)
        return d;
        for(int j=v+1;j<=v+6 && j<n;j++){
            if(vis[j]==0)
            {
                vis[j]=1;
                int d1=d+1;
                int v1;
                if(move[j]!=-1)
                    v1=move[j];
                else
                    v1=j;
                q.push({v1,d1});
            }
        }
    }
    return d;
}

int main()
{
    int n,i,j;
    cin>>n;
    vector<int> v(2*n);
    for(i=0;i<2*n;i++)
    cin>>v[i];
    int x=30;
    int ans=bfs(v,x);
    cout<<ans<<endl;
    return 0;
}