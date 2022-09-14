#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int findPivot(vector<int> &v,int n,int target)
{
    int l=0,h=n-1;
    while(l<=h)
    {
        int m=l+(h-l)/2;
        if(v[m]==target)
        return m;
        if(v[l]<=v[m])
        {
            if(v[l]<=target && v[m]>=target)
            h=m-1;
            else
            l=m+1;
        }
        else{
            if(v[m]<=target && v[h]>=target)
            l=m+1;
            else
            h=m-1;

        }
    }
    return -1;
}

int main()
{
    int n,i,t;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    cin>>t;
    int ans=findPivot(v,n,t);
    cout<<ans<<endl;
    return 0;
}