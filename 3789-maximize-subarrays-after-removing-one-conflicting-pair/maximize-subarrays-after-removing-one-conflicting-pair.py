class Solution(object):
    def maxSubarrays(self, n, conflictingPairs):
        """
        :type n: int
        :type conflictingPairs: List[List[int]]
        :rtype: int
        """
        g = [[] for _ in range(n + 2)]  # conflict list for each number (1-based)

        for a, b in conflictingPairs:
            if a > b:
                a, b = b, a
            g[a].append(b)

        cnt = [0] * (n + 2)
        ans = 0
        b1 = b2 = n + 1  # minimal and second minimal conflicting endpoints

        for a in range(n, 0, -1):
            for b in g[a]:
                if b < b1:
                    b2 = b1
                    b1 = b
                elif b < b2:
                    b2 = b
            ans += (b1 - a)
            cnt[b1] += (b2 - b1)

        return ans + max(cnt)