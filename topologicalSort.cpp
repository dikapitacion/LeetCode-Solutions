#include <bits/stdc++.h> 

void help(int num,map<int,list<int>>& adj, vector<bool>& visited,stack<int>& st){
    visited[num] = 1;

    for(auto neighbour:adj[num]){
        if(!visited[neighbour]){
            help(neighbour,adj,visited,st);
        }
    }

    st.push(num);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    map<int,list<int>> adj;

    for(int i=0;i<e;i++){
        int v = edges[i][0];
        int u = edges[i][1];

        adj[v].push_back(u);
    }
    vector<bool> visited(v,0);
    stack<int> st;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            help(i,adj,visited,st);
        }
    }

    vector<int> ans;

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}