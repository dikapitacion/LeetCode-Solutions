class Solution {
public:
    int solve(vector<int>& nums, int i,int p,vector<vector<int>>& dp){
        if(nums.size()<= i) return 0;

        if(dp[i][p+1] != -1) return dp[i][p+1];

        int notTake = solve(nums,i+1,p,dp);

        int take = 0;
        if(p==-1 || nums[i]>nums[p]){
            take = 1 + solve(nums,i+1,i,dp);
        }
        

        dp[i][p+1] = max(take,notTake);

        return dp[i][p+1];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));

        return solve(nums,0,-1,dp);
    }
};