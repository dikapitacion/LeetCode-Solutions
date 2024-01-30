class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> degree(numCourses,0);

        for(auto i:prerequisites){
            int u = i[1];
            int v = i[0];

            adj[u].push_back(v);
            degree[v]++;
        }

        vector<int> ans;
        queue<int> q;

        for(int i=0;i<numCourses;i++){
            if(degree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int front = q.front();
            ans.push_back(front);
            q.pop();

            for(auto i:adj[front]){
                degree[i]--;
                if(degree[i]==0){
                    q.push(i);
                }
            }
        }

        if(ans.size()==numCourses){
            return ans;
        }
        return {};
    }
};