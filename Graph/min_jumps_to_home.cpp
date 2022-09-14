#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int bfs(vector<int> &v,int n,int a,int b,int k)
{
    queue<int> q;
    vector<vector<int> > vis(2,vector<int>(6000,0));
    vis[0][0]=1;
    vis[1][0]=1;
    q.push(0);
    int ans=0;
    while(!q.empty())
    {
        int sz=q.size();
        while(sz--)
        {
            int pos=q.front();
            if(pos==k)
            return ans;
            q.pop();
            int ax=pos+a;
            int bx=pos-b;
            if(ax<6000 && find(v.begin(),v.end(),ax)==v.end() && vis[0][ax]==0){
                vis[0][ax]=1;
                q.push(ax);
            }
            if(bx>=0 && find(v.begin(),v.end(),bx)==v.end() && vis[0][ax]==0){
                vis[1][bx]=1;
                q.push(bx);
            }
            
        }
        ans++;
        
    }
    return -1;
}


int main()
{
    int a,b,n,i,j,k;
    cin>>n>>a>>b;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    int ans=bfs(v,n,a,b,k);
    cout<<ans<<endl;
    return 0;

}