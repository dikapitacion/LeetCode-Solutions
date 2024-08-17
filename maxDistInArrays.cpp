class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini = arrays[0][0];
        int maxi = arrays[0].back();
        int ans = 0;

        for(int i=1;i<arrays.size();i++){
            ans = max(ans,max(maxi-arrays[i][0],arrays[i].back()-mini));
            maxi = max(arrays[i].back(),maxi);
            mini = min(arrays[i][0],mini);
        }

        return ans;
    }
};