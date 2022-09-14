#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
//one transaction
int max_profit(vector<int> &v,int n)
{
    
    int i,j,res=0,ans=0;
    for(i=0;i<n-1;i++)
    {
        int mx=*max_element(v.begin()+i+1,v.end());
        if(mx>v[i])
        {
            ans=max(ans,mx-v[i]);
        }
    }
    return ans;

}

int main()
{
    int n,i,x;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    int ans=max_profit(v,n);
    cout<<ans<<endl;
    return 0;
}