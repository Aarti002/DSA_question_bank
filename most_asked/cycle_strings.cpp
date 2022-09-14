#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j,sz;
    cin>>n;
    vector<string> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    sz=v[0].length();
    vector<char> s(n),l(n);
    for(i=0;i<n;i++)
    {
        s[i]=v[i][0];
        l[i]=v[i][sz-1];
    }
    vector<int> vis(n,0);
    for(i=0;i<n;i++)
    {
        if(find(s.begin(),s.end(),l[i])!=s.end() && vis[i]!=1)
        vis[i]=1;
    }
    int flag=0;
    for(i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            cout<<"Not possible\n";
            flag=1;
            break;
        }
    }
    if(flag==0)
    cout<<"Yes\n";
    return 0;


}