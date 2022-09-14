#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include<bits/stdc++.h>
using namespace std;

int main(){
	int N,m;
    cout<<"Enter no. of nodes and edegs: ";
	cin >> N >> m;
	vector<pair<int,int> > adj[N]; 
	int wt;
    char a,b;
    cout<<"Enter source and destination with edeg weight: ";
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		adj[a-'a'].push_back(make_pair(b-'a',wt));
		adj[b-'a'].push_back(make_pair(a-'a',wt));
	}	
	vector<int> parent(N),key(N,INT_MAX);
    vector<bool> mstSet(N,false);
    char s;
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
    cout<<"Enter source node: ";
    cin>>s;
    key[s-'a'] = 0; 
    parent[s-'a'] = -1; 
    pq.push({0, s-'a'});

    while(!pq.empty())
    { 
        int u = pq.top().second; 
        pq.pop(); 
        mstSet[u] = true; 
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u;
		        key[v] = weight; 
                pq.push({key[v], v});    
            }
        }
            
    } 
    cout<<"List of parent node for each node: \n";
    for (int i = 0; i < N; i++) 
        cout << parent[i] << " - " << i +'a'<<" \n"; 
	return 0;
} 