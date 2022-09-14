#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
string ans="";
vector<int> kth_permutation_rec(int n,int k)
{
    vector<int> v(n);
    int f=1;
    for(int i=1;i<n;i++){
    f*=i;
    v[i-1]=i;
    }
   // f*=n;
    v[n-1]=n;
    k-=1;
    while(1)
    {
        ans+=to_string(v[k/f]);
        v.erase(v.begin()+(k/f));
        if(v.size()==0)
        break;
        
        k=k%f;
        f=f/v.size();
       // n--;
    }
vector<int> r;
for(int i=0;i<ans.length();i++)
r.push_back(ans[i]-'0');
return r;
}

int main()
{
    int n,b,i,j;
    cin>>n>>b;
    vector<int> v(n);
    for(i=0;i<n;i++)
    v[i]=i+1;
    int k=b;
    
    for(i=0;i<n;i++)
    cout<<v[i]<<" ";
cout<<endl;
    vector<int> res=kth_permutation_rec(n,k);
    for(i=0;i<res.size();i++)
    cout<<res[i]<<" ";

    return 0;
}