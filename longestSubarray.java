class Solution {
    public int longestSubarray(int[] nums) {
        int cur = 0;
        int prev = 0;
        int max = 0;
        boolean z = false;
        for(int num:nums){
            if(num==1){
                cur++;
            }
            else{
                z = true;
                prev = cur;
                cur = 0;
            }
            max = Math.max(cur+prev,max);
        }
        return z ? max:max-1;
    }
}