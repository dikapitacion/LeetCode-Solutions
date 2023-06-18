class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        int dp[][] = new int[m][n];
        if(obstacleGrid[0][0]==1){
            return 0;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j] = 1;
                }
                else if(i==0 && j>=1){
                    if(obstacleGrid[i][j-1]==1 || dp[i][j-1]==0 || obstacleGrid[i][j]==1){
                        dp[i][j] = 0;
                    }
                    else{
                        dp[i][j] = 1;
                    }
                }
                else if(j==0){
                    if(obstacleGrid[i-1][j]==1 || dp[i-1][j]==0 || obstacleGrid[i][j]==1){
                        dp[i][j] = 0;
                    }
                    else{
                        dp[i][j] = 1;
                    }
                }
                else{
                    if(obstacleGrid[i][j]==1){
                        dp[i][j] = 0;
                    }
                    else{
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                    }
                }
            }
        }
        return dp[m-1][n-1];
    }
    
}