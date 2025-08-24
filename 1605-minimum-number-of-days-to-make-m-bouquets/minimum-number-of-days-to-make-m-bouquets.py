class Solution(object):
    def minDays(self, arr, m, k):
        """
        :type bloomDay: List[int]
        :type m: int
        :type k: int
        :rtype: int
        """
        n = len(arr)
        
        # If there are not enough flowers to make m bouquets
        if m * k > n:
            return -1
        
        # Helper function to check if we can make m bouquets by 'day'
        def canMake(day):
            bouquets = 0
            consecutive = 0
            for bloom in arr:
                if bloom <= day:
                    consecutive += 1
                    if consecutive == k:
                        bouquets += 1
                        consecutive = 0
                else:
                    consecutive = 0
            return bouquets >= m
        
        # Binary search range
        left, right = min(arr), max(arr)
        answer = -1
        
        while left <= right:
            mid = (left + right) // 2
            if canMake(mid):
                answer = mid
                right = mid - 1
            else:
                left = mid + 1
        
        return answer
