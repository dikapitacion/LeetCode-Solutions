class Solution {
public:
    int search(vector<int>& nums, int target) {
        int h=nums.size(),l=0;
        if(nums.size()==1){
            if(nums[0]==target){
                return 0;
            }
            else{
                return -1;
            }
        }
        while(h>l){
            int mid = (h+l)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                h = mid;
            }
            else{
                l = mid+1;
            }
        }
        return -1;
    }
};