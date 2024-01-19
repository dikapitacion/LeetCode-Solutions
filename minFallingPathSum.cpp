class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int dp[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0){
                    dp[i][j] = matrix[i][j];
                }
                else if(j==0 && i!=0){
                    dp[i][j] = min(matrix[i][j]+dp[i-1][j],matrix[i][j]+dp[i-1][j+1]);
                }
                else if(j==m-1 && i!=0){
                    dp[i][j] = min(matrix[i][j]+dp[i-1][j],matrix[i][j]+dp[i-1][j-1]);
                }
                else{
                    int mini = min(dp[i-1][j],min(dp[i-1][j+1],dp[i-1][j-1]));
                    dp[i][j] = matrix[i][j]+mini;
                }
            }
        }
        int min = INT_MAX;
        for(int i=0;i<m;i++){
            if(dp[n-1][i]<min){
                min = dp[n-1][i];
            }
        }
        return min;
    }
};