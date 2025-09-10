class Solution(object):
    def sumZero(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        return list(range(1 - n, n, 2))