class Solution {
public:
    void dfs(int node,vector<int> adj[], vector<bool>& visited){
        visited[node] = true;

        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(it,adj,visited);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        vector<bool> visited(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }
        int count = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(i,adj,visited);
            }
        }
        return count;
    }
};