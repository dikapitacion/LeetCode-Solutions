class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int room = q.front();
            q.pop();
            visited[room] = true;
            for(auto i:rooms[room]){
                if(!visited[i]){
                    q.push(i);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
};