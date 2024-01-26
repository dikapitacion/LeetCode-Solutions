class Solution {
public:
    bool dfs(int num,map<int,vector<int>>& adj,vector<int>& visited,vector<int>& pvisited){
        visited[num] = 1;
        pvisited[num] = 1;

        for(auto i:adj[num]){

            if(visited[i]==0){
                if(dfs(i,adj,visited,pvisited)){
                    return true;
                }
            }
            else if(pvisited[i]==1){
                return true;
            }
        }

        pvisited[num] = 0;
        return false;
    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,vector<int>> adj;

        for(auto i:prerequisites){
            adj[i[0]].push_back(i[1]);
        }

        vector<int> visited(numCourses,0),pvisited(numCourses,0);

        for(int i=0;i<numCourses;i++){
            if(visited[i]==0 && dfs(i,adj,visited,pvisited)){
                return false;
            }
        }
        return true;
    }
};