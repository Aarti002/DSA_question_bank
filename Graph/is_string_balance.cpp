//so in this question we have to figure out all balanced set of parenthesis 
//such that characters other than parenthesis remain inside opening n closing brakets

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string s)
{
    int cnt=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')
        cnt++;
        if(s[i]==')')
        cnt--;
        if(cnt<0)
        return false;
    }
    if(cnt>0)
    return false;
    return true;
}

int main()
{
    int i,j,n;
    string s;
    cin>>s;
    //we will use BFS as we need to traverse the string breath wise and push it inside queue
    //if its balance 
    queue<string> q;
    vector<string> ans;
    map<string,int> vis;
    q.push(s);
   
    while(!q.empty())
    {
        string chk=q.front();
        q.pop();
        if(vis[chk])
        continue;
        vis[chk]=1;
        if(isBalanced(chk)){
        ans.push_back(chk);
        continue;
        }
        for(i=0;i<chk.length();i++)
        {
            if(chk[i]=='(' || chk[i]==')')
            {
                string ss=chk.substr(0,i)+chk.substr(i+1,chk.length());
                q.push(ss);
            }
        }

    }
    for(i=0;i<ans.size();i++)
    cout<<ans[i]<<"\n";
    return 0;
}