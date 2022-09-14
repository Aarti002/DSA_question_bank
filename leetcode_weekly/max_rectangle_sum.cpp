#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void findElements(vector<vector<int> > &mat,int n,int m,int i,int j,int tot,int sum,vector<int> &v){
    if(i<0 || i>=n || j<0 || j>=m || tot==0){
    for(int p=0;p<v.size();p++)
    cout<<v[p]<<" ";
    return ;
    }
    if(mat[i][j]<=tot)
    {
        tot-=mat[i][j];
        v.push_back(mat[i][j]);
        findElements(mat,n,m,i+1,j,tot,sum,v);
        findElements(mat,n,m,i-1,j,tot,sum,v);
        findElements(mat,n,m,i,j+1,tot,sum,v);
        findElements(mat,n,m,i,j-1,tot,sum,v);
    }

    
    
}

int main()
{
    int n,m,i,k,j;
    cin>>n>>m>>k;
    vector<vector<int> > mat(n,vector<int>(m));
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
        cin>>mat[i][j];
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(mat[i][j]<=k)
            {
                vector<int> temp;
                int sum=0;
                findElements(mat,n,m,i,j,k,sum,temp);
            }
        }
    }
    
    
    return 0;
}