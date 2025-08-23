class Solution(object):
    def minimumSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m, n = len(grid), len(grid[0])

        def min_area(x1, y1, x2, y2):
            rmin, rmax, cmin, cmax = m, -1, n, -1
            for i in range(x1, x2+1):
                for j in range(y1, y2+1):
                    if grid[i][j]:
                        rmin, rmax = min(rmin, i), max(rmax, i)
                        cmin, cmax = min(cmin, j), max(cmax, j)
            return 0 if rmax == -1 else (rmax - rmin + 1) * (cmax - cmin + 1)

        ans = float('inf')

        # Horizontal splits
        for i1 in range(m-2):
            for i2 in range(i1+1, m-1):
                ans = min(ans,
                          min_area(0, 0, i1, n-1) +
                          min_area(i1+1, 0, i2, n-1) +
                          min_area(i2+1, 0, m-1, n-1))

        # Vertical splits
        for j1 in range(n-2):
            for j2 in range(j1+1, n-1):
                ans = min(ans,
                          min_area(0, 0, m-1, j1) +
                          min_area(0, j1+1, m-1, j2) +
                          min_area(0, j2+1, m-1, n-1))

        # L-shape splits (4 orientations)
        for i in range(m-1):
            for j in range(n-1):
                # Top + bottom-left + bottom-right
                ans = min(ans,
                          min_area(0, 0, i, n-1) +
                          min_area(i+1, 0, m-1, j) +
                          min_area(i+1, j+1, m-1, n-1))
                # Bottom + top-left + top-right
                ans = min(ans,
                          min_area(i+1, 0, m-1, n-1) +
                          min_area(0, 0, i, j) +
                          min_area(0, j+1, i, n-1))
                # Left + top-right + bottom-right
                ans = min(ans,
                          min_area(0, 0, m-1, j) +
                          min_area(0, j+1, i, n-1) +
                          min_area(i+1, j+1, m-1, n-1))
                # Right + top-left + bottom-left
                ans = min(ans,
                          min_area(0, j+1, m-1, n-1) +
                          min_area(0, 0, i, j) +
                          min_area(i+1, 0, m-1, j))

        return ans