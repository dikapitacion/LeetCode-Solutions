class Solution {
    public int findLongestChain(int[][] pairs) {
        // int n = pairs.length;
        // Arrays.sort(pairs,(a,b)->Integer.compare(a[0],b[0]));
        Arrays.sort(pairs, (a, b) -> Integer.compare(a[1], b[1]));
        
        int cur = Integer.MIN_VALUE, ans = 0;
        
        for (int[] pair : pairs) {
            if (cur < pair[0]) {
                cur = pair[1];
                ans++;
            }
        }
        
        return ans;
        // int[][] dp = new int[n][2];
        // dp[0][0] = 0;
        // dp[0][1] = 1;
        // for(int i=1;i<n;i++){
        //     //exclude
        //     dp[i][0] = Math.max(dp[i-1][0],dp[i-1][1]);
        //     //include
        //     //check weather we can include
        //     int num = i-1;
        //     int max = Integer.MIN_VALUE;
        //     int cur = 0;
        //     int flag =0;
        //     while(num>=0 && flag==0){
        //         if(pairs[num][1]<pairs[i][0]){
        //             cur = dp[num][1] + 1;
        //             flag = 1;
        //         }
        //         else{
        //             cur = Math.max(dp[num][0],dp[num][1]);
        //         }
        //         max = Math.max(cur,max);
        //         num--;
        //     }
        //     dp[i][1] = max;
        // }
        // return Math.max(dp[n-1][0],dp[n-1][1]);
    }
}