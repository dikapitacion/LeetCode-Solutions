class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size(),i=0,j=0;
        int ans = 0;
        int cur = 1;
        while(j<n){
            cur*=nums[j];
            j++;
            while(i<j && cur>=k){
                cur/=nums[i];
                i++;
            }
            ans+=(j-i);
        }
        return ans;
    }
};