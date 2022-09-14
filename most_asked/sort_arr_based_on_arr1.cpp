#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,i,x,m;
    cin>>n;
    vector<int> v1(n);
    for(i=0;i<n;i++)
    cin>>v1[i];
    cin>>m;
    vector<int> v2(m),temp;
    for(i=0;i<m;i++)
    cin>>v2[i];
    temp=v1;
    map<int,int> m1;
    
    for(i=0;i<n;i++)
    {
        m1[v1[i]]++;
        if(find(v2.begin(),v2.end(),v1[i])!=v2.end())
        remove(temp.begin(),temp.end(),v1[i]);
    }
    vector<int> ans;
    for(i=0;i<m;i++)
    {

        while(m1[v2[i]]--)
        ans.push_back(v2[i]);
    }
    for(i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    map<int,int> ::iterator it;
    for(i=0;i<temp.size();i++)
    {
        cout<<temp[i]<<" ";
    }
    return 0;
    

}