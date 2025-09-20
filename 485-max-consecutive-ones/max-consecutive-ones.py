class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        curr, max_sum = 0, 0

        for num in nums:
            if num == 1:
                curr += 1
                max_sum = max(curr, max_sum)
            else:
                curr = 0
        return max_sum
        