#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
    cin>>n;
    vector<int> d(n),p(n);

    for(i=0;i<n;i++)
    cin>>d[i];
    for(i=0;i<n;i++)
    cin>>p[i];

    vector<pair<int,int> > vp;
    for(i=0;i<n;i++)
    {
        vp.push_back(make_pair(p[i],d[i]));
    }
    sort(vp.begin(),vp.end());
    reverse(vp.begin(),vp.end());
    vector<pair<int,int> > ::iterator it;
    for(it=vp.begin();it!=vp.end();it++)
    cout<<it->first<<" "<<it->second<<endl;
    int ans=0;
    i=0;
    int td=*max_element(d.begin(),d.end());
    vector<int> res(td+1,-1);
    while(i<n)
    {
        int pos=vp[i].second;
        
        while(pos-- && pos<td)
        {
            if(res[pos]==-1){
            res[pos]=vp[i].first;
            break;}
        }
    i++;
    }
    for(i=0;i<td;i++)
    {if(res[i]!=-1)
    ans+=res[i];}
    cout<<ans<<endl;
    return 0;
}