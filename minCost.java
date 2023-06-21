class Solution {
    public long add(int[] nums, int[] cost,int t){
        long ans = 0L;
        for(int i=0;i<nums.length;i++){
            ans+= 1L * Math.abs(nums[i]-t)*cost[i];
        }
        return ans;
    }
    public long minCost(int[] nums, int[] cost) {
        int l = nums[0];
        int r = nums[0];
        for(int i=0;i<nums.length;i++){
            l = Math.min(l,nums[i]);
            r = Math.max(r,nums[i]);
        }
        long ans=0;
        while(l<r){
            int mid = (l+r)/2;
            long midSum = add(nums,cost,mid);
            long mid1Sum = add(nums,cost,mid+1);
            if(midSum>mid1Sum){
                l = mid+1;
                ans = mid1Sum;
            }
            else{
                r = mid;
                ans = midSum;
            }
        }
        return ans;
    }
}