class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        curr_sum = 0
        n = len(nums)

        for i in range(k):
            curr_sum += nums[i]
        
        max_sum = curr_sum / k

        for i in range(k, n):
            curr_sum += nums[i] - nums[i - k]

            max_sum = max(max_sum, curr_sum / k)
        return max_sum