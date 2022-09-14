#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int first_floor_to_break(int e,int n)
{
    if(n==0 || n==1)
    return n;
    if(e==1)
    return n;
    int ans=INT_MAX; 
    for(int i=1;i<=n;i++)
    ans=min(ans,max(first_floor_to_break(e-1,i-1),first_floor_to_break(e,n-i)));
    return ans+1;
}

int main()
{
    int n,f,k;
    cin>>n>>f;
    int ans=first_floor_to_break(n,f);
    cout<<ans<<endl;
    return 0;
}