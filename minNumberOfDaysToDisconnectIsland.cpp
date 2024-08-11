class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid, vector<vector<bool>>& visited){
        int n = grid.size();
        int m = grid[0].size();
        visited[i][j] = true;
        vector<pair<int,int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};

        for(auto dir:dirs){
            int row = i+dir.first;
            int col = j+dir.second;

            if(row>=0 && row<n && col>=0 && col<m && !visited[row][col] && grid[row][col]==1){
                dfs(row,col,grid,visited);
            }
        }
    }
    int countIslands(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    count++;
                    dfs(i,j,grid,visited);
                }
            }
        }
        return count;
    }

    int minDays(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int initial = countIslands(grid);
        if(initial != 1) return 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    grid[i][j] = 0;
                    int temp = countIslands(grid);
                    grid[i][j] = 1;
                    if(temp!=1) return 1;
                }
            }
        }
        return 2;
    }
};