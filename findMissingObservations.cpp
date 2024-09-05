class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sumM = 0;
        for(auto i:rolls){
            sumM+=i;
        }
        int sumN = (mean*(n+m)) - sumM;
        vector<int> ans(n,0);
        if(sumN<=0 || sumN/n<1) return {};
        for(int i=0;i<sumN;i++){
            ans[i%n]++;
            if(ans[i%n]>6) return {};
        }
        return ans;
    }
};