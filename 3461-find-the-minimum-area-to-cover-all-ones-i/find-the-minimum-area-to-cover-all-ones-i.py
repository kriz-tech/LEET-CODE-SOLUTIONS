class Solution(object):
    def minimumArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        x1 = y1 = float('inf')
        x2 = y2 = float('-inf')
        found = False

        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if val == 1:
                    found = True
                    x1 = min(x1, i)
                    x2 = max(x2, i)
                    y1 = min(y1, j)
                    y2 = max(y2, j)

        if not found: return 0
        return (x2 - x1 + 1) * (y2 - y1 + 1)

