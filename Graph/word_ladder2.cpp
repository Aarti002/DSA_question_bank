#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void dfs(string sw,string tw,vector<string> &path,vector<vector<string> > &ans,map<string,vector<string> > &mp){
    path.push_back(sw);
    if(sw==tw){
        ans.push_back(path);
        return ;
    }
    for(string x:mp[sw])
    {
        dfs(x,tw,path,ans,mp);
      path.pop_back();   
    }
   
}

vector<vector<string> > bfs(vector<string> &wl,string sw,string tw){
    map<string,int> vis;
    map<string,vector<string> > mp;
    vis[sw]=1;
    queue<string> q;
    q.push(sw);
    set<string> st(wl.begin(),wl.end());
    st.erase(sw);
    while(!q.empty()){
            string temp=q.front();
            q.pop();
            
            for(int i=0;i<temp.length();i++){
                for(int j=0;j<26;j++){
                    string p=temp;
                    p[i]='a'+j;
                    if(st.count(p)){
                        if(!vis[p]){
                            q.push(p);
                            vis[p]=vis[temp]+1;
                            mp[temp].push_back(p);
                        }
                        else if(vis[p]==vis[temp]+1)
                        mp[temp].push_back(p);
                        
                    }
                    
                }
        }
    }
    vector<vector<string> > res;
    vector<string> ans;
    dfs(sw,tw,ans,res,mp);
    return res;
}

int main()
{
    int n,i;
    cin>>n;
    vector<string> wl(n);
    for(i=0;i<n;i++)
    cin>>wl[i];
    string sw,tw;
    cin>>sw>>tw;
    vector<vector<string> > ans;
    vector<string> res;
    ans=bfs(wl,sw,tw);
    for(i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++)
        cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    //cout<<res[i]<<" ";
    return 0;
}