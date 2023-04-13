class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3){
            return 0;
        }
        int cont = 0;
        vector<int>dp(n);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2;i<n;i++){
            if(nums[i-1]-nums[i-2]==nums[i]-nums[i-1]){
                dp[i] = dp[i-1] + cont +1;
                cont++;
            }
            else{
                dp[i] = dp[i-1];
                cont = 0;
            }
        }
        return dp[n-1];
    }
};