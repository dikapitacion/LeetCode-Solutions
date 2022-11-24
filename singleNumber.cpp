class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<nums.size()){
            if(i+1<nums.size()){
                if(nums[i]!=nums[i+1]){
                return nums[i];
            }
            else{
                i = i+2;
            }
            }
            else{
                break;
            }
            
        }
        return nums[i];
    }
};