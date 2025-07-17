class Solution(object):
    def maximumLength(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        dp = [[0] * k for _ in range(k)]
        res = 0

        for num in nums:
            x = num % k

            for y in range(k):
                dp[y][x] = dp[x][y] + 1
                res = max(dp[y][x], res)

        return res