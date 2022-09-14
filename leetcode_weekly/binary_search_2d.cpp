#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

 bool binary_search(vector<int> &v,int s,int e,int val)
   {
       int i=s,j=e;
       while(i<=j)
       {
           int m=(j-i)/2;
           if(v[m]==val)
               return true;
           if(val>v[m])
               i=m+1;
           else if(v[m]>val)
               j=m-1;
            
       }
       return false;
       
   }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix[0].size();
        int j=m-1,i=0;
        while(i<matrix.size() && j>=0)
        {
            if(matrix[i][j]==target)
            return true;
            else if(matrix[i][j]>target)
            j--;
            else
            i++;
        }
        return false;
    }

int main()
{
    int n,i,j,m,val;
    cin>>n>>m;
    vector<vector<int> > mat(n,vector<int>(m));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        cin>>mat[i][j];
    }
    cin>>val;
    cout<<searchMatrix(mat,val);
    return 0;
}