#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

vector<string> move(string s,int pos)
{
    vector<string> res(2,s);
    res[0][pos]='0'+(res[0][pos]-'0'+1)%10;
    res[1][pos]='0'+(res[1][pos]-'0'-1+10)%10;
    return res;
}

int maxMove(vector<string> &deadend,string end)
{
    string s="0000";
    unordered_set<string> ends(deadend.begin(),deadend.end()),seen({"0000"});
    queue<string> q;
    q.push(s);
    int ans=0;
    while(!q.empty())
    {
        int sz=q.size();
        while(sz--)
        {
            string chk=q.front();
            q.pop();
            if(chk==end)
            return ans;
            for(int i=0;i<4;i++)
            {
                vector<string> res=move(chk,i);
                for(auto temp:res)
                {
                   // chk[i]='0'+j;
                    if(ends.find(temp)==ends.end() && seen.find(temp)==seen.end())
                    {
                        if(temp==end)
                        return ans;
                        else
                        {
                            q.push(temp);
                            seen.insert(temp);
                        }
                    }
                    
                }
            }
        }
        ans++;
    }
    return 0;
}

int main()
{
    int n,i,j;
    string end;
    cin>>n;
    vector<string> deadends(n);
    for(i=0;i<n;i++)
    cin>>deadends[i];
    cin>>end;
    int ans=maxMove(deadends,end);
    cout<<ans<<endl;
    return 0;
}