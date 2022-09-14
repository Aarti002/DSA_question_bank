#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j,c;
    cin>>n;
    vector<int> in(n),out(n);
    for(i=0;i<n;i++)
    cin>>in[i];
    for(i=0;i<n;i++)
    cin>>out[i];
    cin>>c;
    vector<pair<int,int> > v;
    for(i=0;i<n;i++)
    {
        v.push_back(make_pair(in[i],out[i]));
    }
    sort(v.begin(),v.end());
    
    int flag=0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(i=0;i<v.size();i++)
    {
        if(pq.size()<c)
        pq.push(v[i].second);
        else if(pq.top()<=v[i].first){
            pq.pop();
            pq.push(v[i].second);
        }
        else
        {
            flag=1;
            break;
        }
    }
  //  cnt+=v.size();
    //cout<<v.size()<<endl;
    
    if(flag==1)
    cout<<"No\n";
    else
    cout<<"Yes\n";
    return 0;
}