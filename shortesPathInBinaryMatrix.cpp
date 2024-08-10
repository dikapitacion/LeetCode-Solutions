class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        if(n==1) return !grid[0][0];

        queue<pair<int,int>> q;
        vector<pair<int,int>> dirn={{0,1},{0,-1},{1,0},{-1,0},{1,-1},{-1,1},{1,1},{-1,-1}};

        q.push({0,0});
        int count = 1;

        while(!q.empty()){
            int s = q.size();
            count++;

            while(s--){
                auto [i,j] = q.front();
                q.pop();

                for(auto& dir:dirn){
                    int row = i+dir.first;
                    int col = j+dir.second;

                    if(row>=0 && row<n && col>=0 && col<n && grid[row][col]==0){
                        grid[row][col] = count;
                        q.push({row,col});
                    }
                }
            }
        }

        return !grid[n-1][n-1]?-1:grid[n-1][n-1];

    }
};