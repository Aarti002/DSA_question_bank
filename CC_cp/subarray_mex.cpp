#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,t,x,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>x;
        vector<int> v(n);
        vector<int> temp(k);
        if(x>k)
        cout<<-1<<endl;
        else{
            int i,val=x-1;
            for(i=k-1;i>=0;i--)
            {
                temp[i]=val;
                if(val>0)
                val--;
            }
            for(i=0;i<n;i++)
            {
                v[i]=temp[i%k];
                cout<<v[i]<<" ";
            }
            cout<<endl;
        }
    }
return 0;
}