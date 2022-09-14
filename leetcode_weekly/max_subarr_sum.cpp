#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    int sum=accumulate(v.begin(),v.end(),0);
    int ans=sum;
    i=0;
    int j=n-1;
    while(i<=j)
    {
        if(v[i]<v[j]){
            sum-=v[i];
            i++;
        }
        else{
            sum-=v[j];
            j--;
        }
        ans=max(ans,sum);

    }
    cout<<ans<<endl;
    return 0;
}