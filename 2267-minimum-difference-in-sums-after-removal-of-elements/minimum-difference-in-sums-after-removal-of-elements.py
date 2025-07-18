class Solution(object):
    def minimumDifference(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums) // 3
        length = len(nums)

        pre_sum = [0] * length
        max_heap = []
        left_sum = 0

        for i in range(length):
            heapq.heappush(max_heap, -nums[i])
            left_sum += nums[i]

            if len(max_heap) > n:
                left_sum += heapq.heappop(max_heap)
            if len(max_heap) == n:
                pre_sum[i] = left_sum

        suf_sum = [0] * length
        min_heap = []
        right_sum = 0

        for i in reversed(range(length)):
            heapq.heappush(min_heap, nums[i])
            right_sum += nums[i]

            if len(min_heap) > n: 
                right_sum -= heapq.heappop(min_heap)
            if len(min_heap) == n:
                suf_sum[i] = right_sum

        res = float('inf')
        for i in range(n - 1, 2 * n):
            res = min(res, pre_sum[i] - suf_sum[i + 1])
        
        return res