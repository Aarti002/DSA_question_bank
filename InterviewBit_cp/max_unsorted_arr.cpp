#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> max_subarr_unsort(vector<int> &v,int n)
{
    int i,s=-1,e=-1;
    vector<int> ans;
    for(i=0;i<n-1;i++)
    {
        if(v[i]>v[i+1]){
            s=i;
            break;
        }
    }
    if(s==-1)
    {
        ans.push_back(-1);
        return ans;
    }

    for(i=n-1;i>0;i--)
    {
        if(v[i]<v[i-1]){
            e=i;
            break;
        }
    }
    cout<<s<<" "<<e<<endl;
    int mn=v[s],mx=v[s];
    for(i=s+1;i<=e;i++)
    {
        if(mn>v[i])
        {
          //  s=i;
            mn=v[i];
        }
        else if(mx<v[i]){
           // e=i;
            mx=v[i];
        }
    }
    for(i=0;i<s;i++)
    {
        if(mn<v[i]){
        s=i;
        break;}
    }
    for(i=n-1;i>e;i--)
    {
        if(mx>v[i]){
        e=i;
        break;}
    }
    ans.push_back(s);
    ans.push_back(e);
    return ans;
    
}

int main()
{
    int n,i;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
  /*  int mx=0,ans=INT_MIN,fi=-1,li=-1,flag=0;
    for(i=0;i<n;i++)
    {
        mx+=v[i];
        if(mx<0){
        mx=0;
        li=i;
        flag=0;
        continue;}
        ans=max(ans,mx);
        if(flag!=1){
        fi=i;
        flag=1;
        }
    }
    cout<<ans<<endl;       Kadanes's algo*/
    vector<int> ans=max_subarr_unsort(v,n);
    for(i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";


    return 0;
}