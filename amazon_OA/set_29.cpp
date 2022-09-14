#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    int ksum=0;
    for(i=0;i<k;i++)
    ksum+=v[i];
    i=1;j=k;
    int ans=ksum;
    while(j<n && i<=(n-k))
    {
        ksum+=v[j];
        ksum-=v[i];
        i++;
        j++;
        ans=max(ans,ksum);
    }
    cout<<ans<<endl;
    return 0;

}