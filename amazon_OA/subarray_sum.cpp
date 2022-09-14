#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,m;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    int sum=0,ans=INT_MIN,ch=0,target,l=0;
    cin>>target;
    for(i=0;i<n;i++)
    {
        sum+=v[i];
        while(sum>=target)
        {
            ans=max(ans,i-l+1);
            sum-=v[l];
            l++;
        }
       
    }
    if(ans!=INT_MIN)
    cout<<ans<<endl;
    else
    cout<<0<<endl;
    return 0;
}