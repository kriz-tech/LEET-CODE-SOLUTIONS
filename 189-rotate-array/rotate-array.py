class Solution(object):
    def reverse(self, start, end, nums):
        while start < end:
            nums[start], nums[end] = nums[end], nums[start]
            start += 1
            end -= 1
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k = k % n

        self.reverse(0, n - 1, nums)
        self.reverse(0, k - 1, nums)
        self.reverse(k, n - 1, nums)
        