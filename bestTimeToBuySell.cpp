class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0,max=0,profit=INT_MIN,j=prices.size()-1,lsf = INT_MAX;
//         brute force
        // for(i;i<prices.size();i++){
        //     for(int j=i;j<prices.size();j++){
        //         profit = prices[j]-prices[i];
        //         if(profit>0 && profit>max){
        //             max = profit;
        //         }
        //     }
        // }
        for(i;i<prices.size();i++){
            if(lsf>prices[i]){
                lsf = prices[i];
            }
            profit = prices[i] - lsf;
            if(profit>max){
                max = profit;
            }
        }
        return max;
    }
};