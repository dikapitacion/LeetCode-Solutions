class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double cur = customers[0][0]+customers[0][1];
        double total = cur - customers[0][0];
        int n = customers.size();
        // (5,3)(9,6)(12,16)(15,20)(17,22)(19,23)
        for(int i=1;i<n;i++){
            cur = max(cur,(double)customers[i][0]);
            cur+=customers[i][1];
            total += cur - customers[i][0];
        }
        return total/n;
    }
};