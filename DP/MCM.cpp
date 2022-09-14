#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int MCM(vector<int> &m,int s,int e)
{
    if(s==e)
    return 0;
    int ans=INT_MAX,res;
    for(int i=s;i<e;i++)
    {
        res=MCM(m,s,i)+MCM(m,i+1,e)+m[i]*m[s-1]*m[e];
        ans=min(ans,res);
    }
    return ans;

}

int main()
{
    int n,i;
    cin>>n;
    vector<int> mat(n);
    for(i=0;i<n;i++)
    cin>>mat[i];
    int ans=MCM(mat,1,n-1);
    cout<<ans<<endl;
    return 0;
}