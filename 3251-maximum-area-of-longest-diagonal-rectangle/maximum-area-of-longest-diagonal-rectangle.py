class Solution(object):
    def areaOfMaxDiagonal(self, dia):
        """
        :type dimensions: List[List[int]]
        :rtype: int
        """
        max_prod = -1
        res = 0
        for l, w in dia:
            curr = l * l + w * w
            if curr > max_prod:
                max_prod = curr
                res = l * w
            elif curr == max_prod:
                res = max(res, l * w)
        return res
                
        