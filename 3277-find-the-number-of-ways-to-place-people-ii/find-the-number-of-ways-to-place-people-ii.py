class Solution(object):
    def numberOfPairs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        points.sort(key=lambda p: (p[0], -p[1]))

        ans = 0
        n = len(points)
        for i in range(n):
            maxY = -10**18  # or float('-inf')
            xi, yi = points[i]
            for j in range(i + 1, n):
                _, yj = points[j]
                if yj <= yi and yj > maxY:
                    ans += 1
                    maxY = yj
        return ans