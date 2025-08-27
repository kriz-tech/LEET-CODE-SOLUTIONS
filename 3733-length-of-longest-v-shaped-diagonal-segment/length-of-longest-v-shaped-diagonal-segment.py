class Solution:
    def lenOfVDiagonal(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        directions = [(-1, 1), (1, 1), (1, -1), (-1, -1)]

        @lru_cache(maxsize=None)
        def dfs(i: int, j: int, turned: bool, expected: int, d: int) -> int:
            # Check bounds
            if i < 0 or i >= m or j < 0 or j >= n:
                return 0
            # Check value matches expectation
            if grid[i][j] != expected:
                return 0
            # Determine next expectations
            next_num = 0 if expected == 2 else 2
            di, dj = directions[d]
            best = 1 + dfs(i + di, j + dj, turned, next_num, d)

            # Attempt a clockwise turn if not yet turned
            if not turned:
                nd = (d + 1) % 4
                ndi, ndj = directions[nd]
                best = max(best, 1 + dfs(i + ndi, j + ndj, True, next_num, nd))

            return best

        answer = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    for d in range(4):
                        di, dj = directions[d]
                        answer = max(answer, 1 + dfs(i + di, j + dj, False, 2, d))
        return answer