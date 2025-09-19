class Solution(object):
    def is_sorted(self, nums):
        for i in range(len(nums) - 1):
            if nums[i] > nums[i+1]:
                return False
        return True
    def check(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        n = len(nums)
        for i in range(n):
            rotate = nums[i:] + nums[:i]
            if self.is_sorted(rotate):
                return True
        return False

        