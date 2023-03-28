class Solution {
public:
    int solve(vector<int>& cost){
        int n=cost.size()+1;
        int real[n];
        real[0]=cost[0];
        real[1]=cost[1];
        for(int i=2;i<cost.size();i++){
            real[i] = cost[i] + min(real[i-1],real[i-2]);
        }
        real[cost.size()] = min(real[cost.size()-1],real[cost.size()-2]);
        return real[cost.size()];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        return solve(cost);
    }
};