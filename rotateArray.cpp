class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> ans(nums.size());
        int i = nums.size()-(k%nums.size());
        for(int j=0;j<nums.size();j++){
            ans[j] = nums[(i+j)%nums.size()];
        }
        for(int n=0;n<nums.size();n++){
            nums[n]=ans[n];
        }
    }
};