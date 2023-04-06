class Solution(object):
    def findMinArrowShots(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        points.sort(key = lambda x:x[1])
        n = len(points)
        ans = 1
        end = points[0][1];
        for i in range(1,n):
            if(end<points[i][0]):
                end = points[i][1]
                ans+=1

        return ans