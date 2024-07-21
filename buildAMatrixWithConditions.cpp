class Solution {
public:
    vector<int> topoSort(int k, vector<vector<int>>& conditions){
        vector<vector<int>> adj(k+1);
        vector<int> deg(k+1,0);
        for(auto& it: conditions){
            adj[it[0]].push_back(it[1]);
            deg[it[1]]++;
        }

        queue<int> q;
        for(int i=1;i<=k;i++){
            if(deg[i]==0) q.push(i);
        }

        vector<int> ans;
        int count=0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            ans.push_back(cur);
            count++;
            for(int i:adj[cur]){
                deg[i]--;
                if(deg[i]==0){q.push(i);}
            }
        }

        if(count!=k) return {};
        return ans;
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> mat(k,vector<int>(k,0));
        vector<int> rowSort = topoSort(k,rowConditions);
        vector<int> colSort = topoSort(k,colConditions);
        if(rowSort.empty() || colSort.empty()) return {};
        
        vector<int> pos_i(k+1,-1), pos_j(k+1,-1);
        for(int i=0;i<k;i++){
            pos_i[rowSort[i]] = i;
            pos_j[colSort[i]] = i;
        }

        for(int x=1; x<=k; x++)
            mat[pos_i[x]][pos_j[x]]=x;

        return mat;
    }
};