class Solution(object):
    def longestCommonSubsequence(self, text1, text2):
        """
        :type text1: str
        :type text2: str
        :rtype: int
        """
        n,m = len(text1),len(text2)
        dp = [[0 for i in range(m+1)]for j in range(n+1)]
        ans=0
        for i in range(n-1,-1,-1):
            for j in range(m-1,-1,-1):
                if(text1[i]==text2[j]):
                    dp[i][j] = 1+dp[i+1][j+1]
                else:
                    dp[i][j] = max(dp[i+1][j],dp[i][j+1])
        return dp[0][0]
    #testing      