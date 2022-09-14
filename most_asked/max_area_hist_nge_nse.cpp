#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

//we have to find max area in histogram for that we will be using next greater and next smaller 
// element concept

int main()
{
    int n,i;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    stack<int> nge;
    stack<int> nse;
    vector<int> l(n,0),r(n,0);
    for(i=0;i<n;i++)
    {
        while(!nse.empty() && v[nse.top()]>=v[i])
        nse.pop();
        if(nse.empty())
        l[i]=0;
        else
        l[i]=nse.top()+1;
        nse.push(i);
    }
    for(i=n-1;i>=0;i--)
    {
        while(!nge.empty() && v[nge.top()]>=v[i])
        nge.pop();
        if(nge.empty())
        r[i]=n-1;
        else
        r[i]=nge.top()-1;
        nge.push(i);
    }
    long long int ans=0;
    for(i=0;i<n;i++)
    {
        long long int a=(r[i]-l[i]+1)*v[i];
        ans=max(ans,a);
    }
    cout<<ans<<endl;
    return 0;
}