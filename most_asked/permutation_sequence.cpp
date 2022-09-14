#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i,n,k;
    cin>>n>>k;
    vector<int> ans,v;
    int fact=1;
    for(i=1;i<n;i++){
    fact*=i;
    v.push_back(i);
    }
    v.push_back(i);
    k-=1;
    while(1)
    {
        ans.push_back(v[k/fact]);
        v.erase(v.begin()+k/fact);
        if(v.empty())
        break;
        k=k%fact;
        fact=fact/v.size();
        
    }
    //findPermutations(n,k,ans);
    for(i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    return 0;
}