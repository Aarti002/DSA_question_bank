#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,e,j;
    cin>>n>>e;
    vector<vector<int> > edg(n,vector<int>(n,0));
    vector<vector<int> > con;
    int u,v;
    while(e--)
    {
        cin>>u>>v;
        edg[u][v]=1;
        edg[v][u]=1;
        con.push_back({u,v});
    }
    vector<int> deg(n,0);
    for(i=0;i<n;i++)
    {
        deg[i]=count(edg[i].begin(),edg[i].end(),1);
    }
    int ans=INT_MIN;
    for(i=0;i<con.size();i++){
        int x=deg[con[i][0]];
        int y=deg[con[i][1]];
        ans=max(ans,x+y-1);
    }
    cout<<ans<<endl;
    return 0;

}