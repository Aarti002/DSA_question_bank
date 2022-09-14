#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int isPossible(vector<int> &v,int n,int s)
{
    int dp[n+1][s+1];
    int i,j;
    for(i=0;i<=n;i++)
    dp[i][0]=1;
    for(i=1;i<=s;i++)
    dp[0][i]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=s;j++)
        {
            if(j<=v[i-1])
            dp[i][j]=dp[i-1][j-v[i-1]]||dp[i-1][j];
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    i=n;
    j=s;
    vector<int> s1,s2;
    while(i>0 && j>=0){
        if(dp[i-1][j])
        {
            s1.push_back(v[i-1]);
            i-=1;
        }
        else if(dp[i-1][j-v[i-1]]){
            s2.push_back(v[i-1]);
            j-=v[i-1];
            i--;
        }

    }
    
    return dp[n][s];
}

void printPartition(vector<int> &v,int n,int s)
{
    int i,j;
    int dp[n+1][s+1];
    for(i=0;i<=n;i++)
    dp[i][0]=1;
    for(j=1;j<=s;j++)
    dp[0][j]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=s;j++)
        {
            if(j<=v[i-1])
            dp[i][j]=dp[i-1][j-v[i-1]]||dp[i-1][j];
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    i=n;j=s;
    vector<int> s1,s2;
    while(i>0 && j>=0)
    {
        if(dp[i-1][j])
        {
           s1.push_back(v[i-1]);
           i--; 
        }
        else if(dp[i-1][j-v[i-1]])
        {
            s2.push_back(v[i-1]);
            j-=v[i-1];
            i--;
        }
    }
    cout<<s1.size()<<" "<<s2.size()<<endl;
    for(i=0;i<s1.size();i++)
    cout<<s1[i]<<" ";
    cout<<endl;
    for(i=0;i<s2.size();i++)
    cout<<s2[i]<<" ";
    cout<<endl;
}

int equal_avg_partition(vector<int> &v,int n)
{
    int sum=accumulate(v.begin(),v.end(),0);
    int flag=0;
    for(int i=1;i<n;i++)
    {cout<<"here\n";
        if((sum*i)%n==0){
        int s=(sum*i)/n;

        if(isPossible(v,n,s))
        {
            flag=1;
            cout<<"Yes possible!\n";
            printPartition(v,n,s);
            break;
        }
        }

    }
    if(flag!=1)
    cout<<"Not possible\n";
    return 0;
}

int main()
{
    int n,i;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
    cin>>v[i];
    int sum=accumulate(v.begin(),v.end(),0);
    equal_avg_partition(v,n);
    return 0;
}