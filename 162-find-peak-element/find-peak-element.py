class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_num = max(nums)
        return nums.index(max_num)
        