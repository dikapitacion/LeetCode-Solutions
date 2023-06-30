class Solution {
    public int pivotIndex(int[] nums) {
        int r = 0,l=0;
        int n = nums.length;
        for(int i=0;i<n;i++){
            r+=nums[i];
        }

        for(int i=0;i<n;i++){
            r-=nums[i];
            if(r==l){
                return i;
            }
            l+=nums[i];
        }
        return -1;
    }
}