class Solution {
    public int[] getAverages(int[] nums, int k) {
        if(k==0){
            return nums;
        }
        int n = nums.length;
        int avgs[] = new int[n];
        Integer avg = 0;
        Integer sum = 0;
        int r = (2*k)+1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(i<k || n-i<=k){
                avgs[i] = -1;
            }
            if(i>=2*k){
                avg = sum/r;
                if(avg == -7372){
                    avg = 100000;
                }
                
                avgs[i-k] = avg;
                sum = sum - nums[i-2*k];
            }
        }
        return avgs;
    }
}