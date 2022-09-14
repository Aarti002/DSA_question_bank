#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    {
        cin>>v[i];
    }
    stack<int> stk;
    vector<int> span(n,1);
    // for(i=1;i<n;i++)
    // {
    //     int p=i;
    //     while(p--)
    //     {
    //         if(v[p]<=v[i])
    //         span[i]++;
    //         else
    //         break;
    //     }
    // }
    for(i=0;i<n;i++)
    {
        while(!stk.empty() && v[i]>=v[stk.top()])
        stk.pop();
        if(stk.empty())
        span[i]=i+1;
        else
        span[i]=i-stk.top();
        stk.push(i);
    }
    for(i=0;i<n;i++)
    cout<<span[i]<<" ";
    return 0;
}