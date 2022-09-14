#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int max_sum_inc_subseq(vector<int> &v,int n)
{
    int i,j;
    vector<int> res=v;
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(v[i]>v[j] && res[i]<(res[j]+v[i]))
            res[i]=res[j]+v[i];
        }
    }
    return *max_element(res.begin(),res.end());
}

int main()
{
    int i,n;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    int ans=max_sum_inc_subseq(v,n);
    cout<<ans<<endl;
    return 0;
}