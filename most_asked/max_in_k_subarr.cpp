#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i,n,j,x,k;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    queue<int> q;
    cin>>k;

    int mx=*max_element(v.begin(),v.begin()+k);
    q.push(mx);
    vector<int> ans(n-k+1);
    int p=0;
  /*  i=0;j=k-1;
    while(j<n)
    {
        mx=max(mx,v[j]);
        ans[p]=mx;
        p++;
        i++;
        j++;
    }  
    for(i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    return 0;*/
 //everything in above approach is correct except one corner case what 
 //if the maximum element which is being used in this case gets removed from 
 //window then we need to use second next element from previous window so will make
 // use of such data structure who works in that manner i.e queue
j=0;i=0;
 while(j<n)
 {
    while(v[j]>q.front() && !q.empty())
    q.pop();
    q.push(v[j]);
    if((j-i+1)==k){
    cout<<q.front()<<" ";
    i++;
    }
    j++;
 }
 return 0;
}