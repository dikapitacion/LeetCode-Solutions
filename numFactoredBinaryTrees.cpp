class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int MOD = 1e9 + 7;
        int n = arr.size();
        unordered_map<int,int> dp;
        sort(arr.begin(),arr.end());
        unordered_set<int> s(arr.begin(),arr.end());
        for(int i:arr){
            dp[i] = 1;
        }
        // for(int i=0;i<n;i++){
        //     vector<int> fact;
        //     for(int j=0;j<i;j++){
        //         if(arr[i]%arr[j]==0 && s.find(arr[i]/arr[j])!=s.end()){
        //             long long temp = (long long)dp[arr[j]] * dp[arr[i]/arr[j]];
        //             if(arr[i]/arr[j] == arr[j]){
        //                 dp[arr[i]] = (dp[arr[i]]+temp) % MOD;
        //             }
        //             else{
        //                 dp[arr[i]] = (dp[arr[i]]+temp*2)%MOD;
        //             }
        //         }
        //     }
        // }
        for (int i : arr) {
            for (int j : arr) {
                if (j > std::sqrt(i)) break;
                if (i % j == 0 && s.find(i / j) != s.end()) {
                    long long temp = (long long)dp[j] * dp[i / j];
                    if (i / j == j) {
                        dp[i] = (dp[i] + temp) % MOD;
                    } else {
                        dp[i] = (dp[i] + temp * 2) % MOD;
                    }
                }
            }
        }

        int ans = 0;
        for(auto& [i,val]:dp){
            ans = (ans+val)%MOD;
        }
        return ans;
        
    }
};