#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    int ans=INT_MIN,res=0;
    for(i=0;i<n;i++)
    {
        res+=v[i];
        ans=max(ans,res);
        if(res<0)
        res=0;
    }
    cout<<ans<<endl;
    return 0;
}