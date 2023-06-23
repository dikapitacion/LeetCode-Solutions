class Solution {
    public int prof(int[] prices,int[][] dp, int bot,int i,int fee){
        if(i==prices.length){
            return 0;
        }
        if(dp[i][bot] != 0){
            return dp[i][bot];
        }
        int profit;
        if(bot==0){
            int sold = prices[i]-fee + prof(prices,dp,1,i+1,fee);
            int skip = prof(prices,dp,0,i+1,fee);
            profit = Math.max(sold,skip);
        }
        else{
            int buy = -prices[i] + prof(prices,dp,0,i+1,fee);
            int skip = prof(prices,dp,1,i+1,fee);
            profit = Math.max(buy,skip);
        }
        return dp[i][bot] = profit;
    }
    public int maxProfit(int[] prices, int fee) {
       int n = prices.length;
       int bot = 1;
       int[][] dp = new int[n][2];
       int ans = prof(prices,dp,bot,0,fee);
       return ans;
    }
}