class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> inDeg(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(auto j:graph[i]){
                adj[j].push_back(i);
                inDeg[i]++;
            }
        }

        queue<int> q;
        vector<int> ans;

        for(int i=0;i<n;i++){
            if(inDeg[i]==0) q.push(i);
        }

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            ans.push_back(cur);

            for(auto i:adj[cur]){
                inDeg[i]--;
                if(inDeg[i]==0) q.push(i);
             }
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};