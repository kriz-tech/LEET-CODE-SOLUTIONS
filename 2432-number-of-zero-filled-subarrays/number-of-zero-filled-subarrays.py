class Solution(object):
    def zeroFilledSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = 0
        count = 0

        for num in nums:
            if num == 0:
                count += 1
                res += count
            else:
                count = 0
        return res
        