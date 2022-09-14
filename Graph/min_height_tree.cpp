#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;



int main(){
    int n,e,i,u,v;
    cin>>n>>e;
    vector<vector<int>> adj(n);
    vector<int> ind(n,0);
    while(e--){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ind[u]++;
        ind[v]++;
    }
    queue<int> q;
    for(i=0;i<n;i++){
        if(ind[i]==1)
        q.push(i);
    }
    vector<int> ans;
    while(!q.empty()){
        ans.clear();
        int sz=q.size();
        while(sz--){
            int p=q.front();
            q.pop();
            ans.push_back(p);
            for(auto &x:adj[p])
            {
                ind[x]--;
                if(ind[x]==1)
                q.push(x);
            }
        }
    }
    for(auto x:ans)
    cout<<x<<" ";
    cout<<endl;
    return 0;

}