class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<vector<bool>>& visited,int row,int col){
        visited[row][col] = true;
        
        int n = grid.size(),m=grid[0].size();
        if(row-1>=0){
            if(grid[row-1][col] == 1 && !visited[row-1][col]){
                
                dfs(grid,visited,row-1,col);
            }
        }
        if(row+1<n){
            if(grid[row+1][col] == 1 && !visited[row+1][col]){
                
                dfs(grid,visited,row+1,col);
            }
        }
        if(col-1>=0){
            if(grid[row][col-1] == 1 && !visited[row][col-1]){
                
                dfs(grid,visited,row,col-1);
            }
        }
        if(col+1<m-1){
            if(grid[row][col+1] == 1 && !visited[row][col+1]){
            
                dfs(grid,visited,row,col+1);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(),m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    if(i==0 || i==n-1 || j==0 || j==m-1){
                        dfs(grid,visited,i,j);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};