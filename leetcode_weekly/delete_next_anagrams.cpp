#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
    cin>>n;
    vector<string> v(n),temp;
    for(i=0;i<n;i++){
    cin>>v[i];
    string p=v[i];
    sort(p.begin(),p.end());
    temp.push_back(p);
    }
    vector<int> ers;
    for(i=1;i<n;i++)
    {
        if(temp[i-1]==temp[i])
        ers.push_back(i);
    }
    for(i=0;i<v.size();i++){
        if(find(ers.begin(),ers.end(),i)==ers.end())
    cout<<v[i]<<endl;
    }
    return 0;
    
}