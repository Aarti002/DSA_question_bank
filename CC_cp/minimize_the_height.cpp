#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,k;
    cin>>n>>k;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    sort(v.begin(),v.end());
    int mx=v[n-1];
    int mn=v[0];
    int ans=mx-mn;
    for(i=1;i<n;i++)
    {
        if(v[i]<k)
        continue;
        else{
            mn=min(v[0]+k,v[i]-k);
            mx=max(v[n-1]-k,v[i-1]+k);
            ans=min((mx-mn),ans);
        }
        //cout<<v[i]<<" ";
    }
    cout<<ans<<endl;
    return 0;
}