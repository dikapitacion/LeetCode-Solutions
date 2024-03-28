class Solution {
public:
    int solve(string& s,string& rs,int i,int j,vector<vector<int>>& dp){
        if(i==s.size() || j==s.size()){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s[i] == rs[j]){
            dp[i][j] = 1 + solve(s,rs,i+1,j+1,dp);
            return dp[i][j];
        }

        dp[i][j] = max(solve(s,rs,i+1,j,dp),solve(s,rs,i,j+1,dp));
        return dp[i][j];
    }
    int longestPalindromeSubseq(string s) {
        string rs = s;
        int n = s.size();
        reverse(rs.begin(),rs.end());
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        return solve(s,rs,0,0,dp);
    }
};