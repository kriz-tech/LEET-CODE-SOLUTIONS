class Solution(object):
    def maximumLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        dp = [[0, 0], [0, 0]]
        res = 0

        for num in nums:
            x = num % 2
            prev_dp = [row[:] for row in dp]

            for j in range(2):
                y = (j - x - 2) % 2
                dp[y][x] = max(dp[y][x], prev_dp[x][y] + 1)
                res = max(res, dp[y][x])
        return res
        