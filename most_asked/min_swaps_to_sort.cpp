#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    vector<pair<int,int> > vp;
    for(i=0;i<n;i++)
    {
        vp.push_back({v[i],i});
    }
    sort(vp.begin(),vp.end());
    vector<int> vis(n,0);
    int ans=0;
    for(i=0;i<n;i++)
    {
        int x=vp[i].second;
        int y=vp[x].second;
        cout<<x<<" "<<y<<endl;
        if(x!=y && vis[x]==0 && vis[y]==0)
        {
            ans++;
            vis[x]=1;
            vis[y]=1;
        }
        
    }
    cout<<ans<<endl;
    return 0;
}