class Solution {
    public int first(int[] nums, int target){
        int lo = 0;
        int hi = nums.length-1;
        int min = -1;
        while(lo<=hi){
            int mid = (hi-lo)/2 + lo;
            if(nums[mid]==target){
                min=mid;
                hi=mid-1;
            }
            else if(nums[mid]>target){
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return min;
    }
    public int last(int[] nums, int target){
        int lo = 0;
        int hi = nums.length-1;
        int max = -1;
        while(lo<=hi){
            int mid = (hi-lo)/2 + lo;
            if(nums[mid]==target){
                max=mid;
                lo=mid+1;
            }
            else if(nums[mid]>target){
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return max;
    }
    public int[] searchRange(int[] nums, int target) {
        int[] ans = {-1,-1};
        
        int min=first(nums,target),max = last(nums,target);
        

        ans[0] = min;
        ans[1] = max;
        
        return ans;
    }
}