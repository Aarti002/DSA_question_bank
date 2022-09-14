#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

vector<int> next_greater_element(vector<int> &v,int n)
{
    stack<int> stk;
    int i;
    vector<int> res(n);
    for(i=n-1;i>=0;i--)
    {
        if(stk.empty()){
        res[i]=-1;
        stk.push(v[i]);
        }
        else{
            while(!stk.empty() && stk.top()<=v[i] )
            stk.pop();
            if(stk.empty())
            res[i]=-1;
            else
            res[i]=stk.top();
            stk.push(v[i]);
        }
    }
    return res;
}

vector<int> next_smallest_element(vector<int> &v,int n)
{
    stack<int> stk;
    int i;
    vector<int> res(n);
    for(i=n-1;i>=0;i--)
    {
        if(stk.empty()){
        res[i]=-1;
        stk.push(v[i]);
        }
        else{
            while(!stk.empty() && stk.top()>=v[i] )
            stk.pop();
            if(stk.empty())
            res[i]=-1;
            else
            res[i]=stk.top();
            stk.push(v[i]);
        }
    }
    return res;
}


int main()
{
    int n,i;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    vector<int> nge=next_greater_element(v,n);
    vector<int> nse=next_smallest_element(v,n);
    for(i=0;i<nse.size();i++)
    cout<<nse[i]<<" ";
    cout<<endl;
    for(i=0;i<nge.size();i++)
    cout<<nge[i]<<" ";
    return 0;
}