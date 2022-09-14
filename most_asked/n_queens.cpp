#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int> > &chess,int r,int c,int n)
{
    for(int i=r-1,j=c-1;i>=0 && j>=0;i--,j--)
    {
        if(chess[i][j])
        return false; 
    }
    for(int i=r-1,j=c;i>=0;i--)
    {
        if(chess[i][j])
        return false;
    }
    for(int i=r-1,j=c+1;i>=0 && j<n;i--,j++)
    {
        if(chess[i][j])
        return false;
    }
    return true;
}

bool placeQueens(vector<vector<int> > &chess,int n,int r)
{
    if(r>=n)
    return true;
    for(int c=0;c<n;c++)
    {
        if(chess[r][c]==0 && isSafe(chess,r,c,n)){
        chess[r][c]=1;
        if(placeQueens(chess,n,r+1))
        return true;
        chess[r][c]=0;
        }
    }
    return false;
}

int main()
{
    int n,i,j;
    cin>>n;
    vector<vector<int> > chess(n,vector<int>(n,0));
    if(!placeQueens(chess,n,0))
    cout<<"Solution doesn't exist!\n";
    else{
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        cout<<chess[i][j]<<" ";
        cout<<endl;
    }}
    return 0;
}