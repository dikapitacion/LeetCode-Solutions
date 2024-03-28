class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int,int> map;
        int left = 0,right=0,n = nums.size();
        int maxi = 0;
        while(right<n){
            map[nums[right]]++;
            while(map[nums[right]]>k){
                map[nums[left]]--;
                left++;
            }
            maxi = max(maxi,right-left+1);
            right++;
        }
        return maxi;
    }
};