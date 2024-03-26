class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,0);
        queue<int> q;
        for(int i=0;i<n;i++){
            if(color[i]==0){
                q.push(i);
        bool flag = false;
        while(!q.empty()){
            int s = q.size();
            int i=0;
            flag = !flag;
            while(i<s){
                int front = q.front();
                if(flag){
                    color[front] = 2;
                }
                else{
                    color[front] = 1;
                }
                q.pop();
                for(auto t:graph[front]){
                    if(color[t]==0){
                        q.push(t);
                    }
                    else if(color[t] == color[front]){
                        return false;
                    }
                }
                i++;
            }
        }
            }
        }
        
        return true;
    }
};