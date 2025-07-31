class Solution(object):
    def subarrayBitwiseORs(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        res = set()
        prev = set()

        for num in arr:
            curr = set([num])
            for x in prev:
                curr.add(x | num)
            res |= curr
            prev = curr

        return len(res)
        