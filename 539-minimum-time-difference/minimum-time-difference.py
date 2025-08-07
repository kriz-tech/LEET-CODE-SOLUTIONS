class Solution(object):
    def findMinDifference(self, tp):
        """
        :type timePoints: List[str]
        :rtype: int
        """
        def time_to_min(t):
            h, m = map(int, t.split(":"))
            return h * 60 + m
            
        times = sorted(time_to_min(t) for t in tp)

        res = float('inf')
        for i in range(1, len(times)):
            diff = times[i] - times[i - 1]
            res = min(res, diff)

        wrap_effect = 1440 - times[-1] + times[0]
        return min(res, wrap_effect)
