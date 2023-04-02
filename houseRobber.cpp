class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        else if(n==2){
            return max(nums[0],nums[1]);
        }
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int include = dp[i-2]+nums[i];
            int exclude = dp[i-1]+0;
            dp[i]=max(include,exclude);
        }
        return dp[n-1];
    }
};