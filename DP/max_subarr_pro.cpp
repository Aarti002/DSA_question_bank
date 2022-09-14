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
    int mxr=1,mxl=1,z=0;
    int ansr=INT_MIN,ansl=INT_MIN;
    int ans;
    for(i=0;i<n;i++)
    {
        mxr*=v[i];
        if(mxr==0)
        {
            z=1;
            mxr=1;
            continue;
        }
        ansr=max(ansr,mxr);
    }
    for(i=n-1;i>=0;i--)
    {
        mxl*=v[i];
        if(mxl==0)
        {
            z=1;
            mxl=1;
            continue;
        }
        ansl=max(ansl,mxl);
    }
    if(z==1)
    ans=max(max(ansr,ansl),0);
    else
    ans=max(ansr,ansl);
    cout<<ans<<endl;
    return 0;

}