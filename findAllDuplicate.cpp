class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n+1,0);
        vector<int> ans;
        for(auto i:nums){
            arr[i]++;
            if(arr[i]>=2){
                ans.push_back(i);
            }
        }
        return ans;
    }
};