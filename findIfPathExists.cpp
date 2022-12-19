class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        map<int,vector<int>> l;
        for(auto i:edges){
            int a = i[0],b=i[1];
            l[a].push_back(b);
            l[b].push_back(a);
        }
        queue<int> q;
        vector<bool> seen(n);
        seen[source] = true;
        q.push(source);
        while(!q.empty()){
            int p = q.front();
            if(p==destination){
                return true;
            }
            q.pop();
            for(auto i:l[p]){
                if(!seen[i]){
                    q.push(i);
                    seen[i]=true;
                }
            }
        }
        return false;
    }
};