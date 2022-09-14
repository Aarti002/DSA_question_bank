#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,i,j;
    cin>>n>>m;
    vector<vector<int> > mat(n,vector<int>(m));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        cin>>mat[i][j];
    }
    vector<int> hgt(n,0);
    for(i=0;i<n;i++)
    {
        hgt[i]=count(mat[i].begin(),mat[i].end(),1);
    }
    
}