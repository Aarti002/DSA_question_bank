#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,t,i,j;
    cin>>n;
    vector<vector<int> > per(n,vector<int>(n));
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        cin>>per[i][j];
    }
    vector<vector<int> > knw(n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(per[i][j])
            knw[j].push_back(i);
         //   knw[j]+=per[i][j];
        }
    }
    vector<int> cele;
    int c=0,flag=0;
    for(i=1;i<n;i++)
    {
       if(per[c][i])
       c=i;
    }
    for(i=0;i<n;i++)
    {
        if(c!=i && (per[c][i] || per[i][c]==0))
        {
            cout<<"No\n";
            flag=1;
            break;
        }
    }
    if(flag==0)
    cout<<c<<endl;
    return 0;
}