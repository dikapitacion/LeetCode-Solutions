class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> farr;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    farr.push_back(i);
                    farr.push_back(j);
                    break;
                }
            }
        }
        return farr;
        
    }
};