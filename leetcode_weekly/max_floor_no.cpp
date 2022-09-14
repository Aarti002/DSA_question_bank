#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l,r,i,n,x;
    cin>>l>>r;
    cin>>n;
    vector<int> f(n);
    for(i=0;i<n;i++)
    {cin>>f[i];}
    sort(f.begin(),f.end());
    int ans=0,res,prev=l;
    for(i=0;i<n;i++)
    {
        res=f[i];
        ans=max(ans,res-prev);
        prev=res+1;
    }
    ans=max(ans,r-f[n-1]);

    cout<<ans<<endl;
    return 0;

}