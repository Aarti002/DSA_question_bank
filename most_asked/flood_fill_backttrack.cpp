#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string> 
#include <bits/stdc++.h>
using namespace std;

void allPath(vector<vector<int> > &v,int n,int m,int r,int c,string res)
{
    
    if(r==n || c==m || r<0 || c<0 || v[r][c]==1)
    return ;
    if(r==n-1 && c==m-1)
    {
        cout<<res<<endl;
        return ;
    }
    allPath(v,n,m,r-1,c,res+"u");
    allPath(v,n,m,r,c-1,res+"l");
    allPath(v,n,m,r+1,c,res+"d");
    allPath(v,n,m,r,c+1,res+"r");
    
}

int main()
{
    int n,i,j,m;
    cin>>n>>m;
    vector<vector<int> > v(n,vector<int>(m));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        cin>>v[i][j];
    }
    string res="";
    allPath(v,n,m,0,0,"");
    return 0;
}