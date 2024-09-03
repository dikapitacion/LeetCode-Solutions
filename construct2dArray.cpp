class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int cur = 0;
        if(m*n != original.size()) return {};
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j] = original[cur++];
            }
        }

        return ans;
    }
};