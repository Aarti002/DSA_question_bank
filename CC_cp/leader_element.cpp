#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    vector<int> ans;
    for(i=n-1;i>=0;i--)
    {
        int m=*max_element(v.begin()+i,v.end());
        if(m<v[i])
        ans.push_back(v[i]);
    }
    for(i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}