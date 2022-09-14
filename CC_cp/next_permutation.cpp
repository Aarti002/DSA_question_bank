#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
    cin>>n;
    vector<int> p(n);
    for(i=0;i<n;i++)
    cin>>p[i];
    int pos=-1;
    for(i=n-1;i>0;i--)
    {
        if(p[i-1]<p[i])
        {
            pos=i;
            break;
        }
    }
    if(pos==-1)
    sort(p.begin(),p.end());
    else
    {
        int t=pos;
        for(i=n-1;i>pos;i--)
        {
            if(p[i]>p[pos-1] && p[i]<p[t])
            t=i;
        }
        swap(p[t],p[pos-1]);
        sort(p.begin()+pos,p.end());
    }
    for(i=0;i<n;i++)
    cout<<p[i]<<" ";
    return 0;
}