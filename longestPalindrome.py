class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        ans = s[0]
        if(s==s[::-1]):
            return s
        for i in range(1,len(s)):
            start = 0
            end = i
            # found = False
            while(end<=len(s)):
                window = s[start:end]
                rwindow = window[::-1]
                if window == rwindow:
                    ans = window
                    # found = True
                end +=1
                start+=1
        return ans   