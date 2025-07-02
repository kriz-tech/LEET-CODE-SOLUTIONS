class Solution(object):
    def maxProduct(self, arr):
        """
        :type nums: List[int]
        :rtype: int
        """
        left, right = 1, 1
        ans = arr[0]
		
        for i in range(len(arr)):
		    left = 1 if left == 0 else left
		    right = 1 if right == 0 else right
		    
		    left *= arr[i]
		    
		    right *= arr[len(arr) - 1 - i]
		    
		    ans = max(ans, max(left, right))
        return ans
        