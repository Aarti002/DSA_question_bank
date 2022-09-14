#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,i,j;
    cin>>n;
    vector<int> arr(n),dep(n);
    for(i=0;i<n;i++)
    cin>>arr[i];
    for(i=0;i<n;i++)
    cin>>dep[i];
    //vector<pair<int,int> > plt;
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
   // for(i=0;i<n;i++)
    //plt.push_back(make_pair(arr[i],dep[i]));
    //sort(plt.begin(),plt.end());
    i=0;j=0;
    int plt=0;
    int ans=INT_MIN;
    while(i<n && j<n)
    {
        if(arr[i]<=dep[j])
        {
            plt+=1;
            i++;
        }
        else{
        j++;
        plt-=1;
        }
        ans=max(ans,plt);
    }


    cout<<ans<<endl;
    return 0;
}