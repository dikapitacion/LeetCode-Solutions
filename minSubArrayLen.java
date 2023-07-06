class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int f = 0;
        int l = 0;
        int sum = 0;
        int count = Integer.MAX_VALUE;
        while(l<nums.length){
            sum+=nums[l];
            while(sum>=target){
                sum-=nums[f];
                count = Math.min(l-f+1,count);
                f++;
            }
            l++;
        }
        if(count == Integer.MAX_VALUE){
            return 0;
        }
        return count;
    }
}