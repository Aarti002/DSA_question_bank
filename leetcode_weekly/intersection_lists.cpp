#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,i,j;
    cin>>n>>m;
    vector<int> v1(n),v2(m),com;
    for(i=0;i<n;i++)
    cin>>v1[i];
    for(i=0;i<m;i++)
    cin>>v2[i];
    j=0;
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    while(i<n && j<m)
    {
        if(v1[i]==v2[j])
        {
            i++;
            j++;
        }
        else if(v1[i]<v2[j])
        v1.erase(v1.begin()+i);
        else
        v2.erase(v2.begin()+j);
    }
    if(v2.size()<v1.size())
    com=v2;
    com=v1;
    for(i=0;i<com.size();i++)
    cout<<com[i]<<" ";
    return 0;
}