class Solution(object):
    def findMaxAverage(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """
        curr_sum = 0
        n = len(nums)

        for i in range(k):
            curr_sum += nums[i]
        
        max_sum = curr_sum

        for i in range(k, n):
            curr_sum += nums[i] - nums[i - k]

            max_sum = max(max_sum, curr_sum)
        return float (max_sum) / k
        