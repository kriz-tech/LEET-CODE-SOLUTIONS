class Solution:
    def earliestAndLatest(self, n: int, firstPlayer: int, secondPlayer: int) -> List[int]:
        @lru_cache(None)
        def dp(l, r, k):
            if l == r:
                return (1, 1)
            if l > r:
                return dp(r, l, k)
            earliest, latest = math.inf, -math.inf
            for i in range(1, l+1):
                for j in range(l - i + 1, r - i + 1):
                    if not (l + r - k // 2 <= i + j <= (k + 1) // 2):
                        continue
                    e, L = dp(i, j, (k+1)//2)
                    earliest = min(earliest, e + 1)
                    latest   = max(latest, L + 1)
            return (earliest, latest)

        l = firstPlayer
        r = n - secondPlayer + 1
        return list(dp(l, r, n))