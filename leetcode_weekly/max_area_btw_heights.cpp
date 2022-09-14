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
    int ans=INT_MIN;
    i=0;j=n-1;
    while(i<j)
    {
        int h=min(v[i],v[j]);
        int area=h*(j-i);
        ans=max(area,ans);
        while(i<j && v[i]<=h)
        i++;
        while(i<j && v[j]<=h)
        j--;
    }
    cout<<ans<<endl;
    return 0;
}