class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,vector<int>> adj;
        vector<bool> trusted(trust.size()+1,false);
        for(auto it:trust){
            adj[it[1]].push_back(it[0]);
            trusted[it[0]] = true;
        }
        
        for(int i=1;i<=n;i++){
            if(!trusted[i]){
                if(adj[i].size() >= n-1){
                    return i;
                }
            }
        }
        return -1;
    }
};