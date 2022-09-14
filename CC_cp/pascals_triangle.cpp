#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j;
    cin>>n;
    vector<vector<int> > pas(n,vector<int>(n,0));
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            if(j==0 || j==i)
            pas[i][j]=1;
            else{
                pas[i][j]=pas[i-1][j-1]+pas[i-1][j];
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        cout<<pas[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}