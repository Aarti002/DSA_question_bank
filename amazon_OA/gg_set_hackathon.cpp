#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,m,j;
    string s;
    cin>>n>>m;
    vector<string> v1(n),v2(m);
    vector<vector<int> > v1c(n,vector<int>(26,0));
    vector<vector<int> > v2c(m,vector<int>(26,0));
    for(i=0;i<n;i++){
    cin>>v1[i];
    for(int k=0;k<v1[i].length();k++)
    v1c[i][v1[i][k]-'a']++;
    }
    for(i=0;i<m;i++){
    cin>>v2[i];
    for(int k=0;k<v2[i].length();k++)
    v2c[i][v2[i][k]-'a']++;
    }
    vector<int> ans;
    for(i=0;i<m;i++){
        int cnt=0;
        for(j=0;j<n;j++){
            int flag=0;
            for(int k=0;k<26;k++)
            {
                if(v2c[i][k]>v1c[j][k])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            cnt++;
        }
        ans.push_back(cnt);
    }
    
    for(i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    return 0;
}