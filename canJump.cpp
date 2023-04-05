class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool> dp(n,false);
        dp[0]=true;
        int i=0;
        for(int i=0;i<n;i++){
            if(dp[i]){
                if(nums[i]+i>=n){
                    return true;
                }
                for(int j=i;j<=nums[i]+i;j++){
                    dp[j] = true;
                }
            }
        }
        return dp[n-1];
    }
};