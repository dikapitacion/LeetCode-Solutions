class Solution(object):
    def removeStars(self, s):
        """
        :type s: str
        :rtype: str
        """
        ans = ''
        for i in s:
            if i!='*':
                ans+=i
            else:
                ans = ans[:-1]
        return ans
            