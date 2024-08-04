class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> all;
        int sum;
        for(int i=0;i<n;i++){
            sum=0;
            for(int j=i;j<n;j++){
                sum += nums[j];
                all.push_back(sum);
            }
        }

        sort(all.begin(), all.end());
        sum = 0;
        int MOD = 1000000007;
        for(int i=left-1;i<right;i++){
            sum = (sum + all[i])%MOD;
        }

        return sum;
    }
};