class Solution {
public:
    int solve(vector<vector<int>>& grid, int row, int col,vector<vector<int>>& dp){
        if ( row == grid.size()-1){
            return grid[row][col];
        }

        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        
        int mini = 1e9;
        for(int i=0;i<grid.size();i++){
            if(i!=col){
                mini = min(mini, grid[row][col]+solve(grid, row + 1, i, dp));
            }
        }

        return dp[row][col]= mini;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        if(n==1) return grid[0][0];
        int mini = 1e9;
        for(int i=0;i<n;i++){
            mini = min (mini, solve(grid,0,i,dp));
        }
        return mini;
        
    }
};