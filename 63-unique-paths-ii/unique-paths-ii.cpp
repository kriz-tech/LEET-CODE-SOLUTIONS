class Solution {
public:
    int up(vector<vector<int>> &o, int row, int col, int m, int n, vector<vector<int>>&dp)
    {
        if(row == m || col == n) return 0;
        if(o[row][col] != 0) return 0;
        if(row == m - 1 && col == n - 1) return 1;
        if(dp[row][col] != -1) return dp[row][col];
        return dp[row][col] = up(o,row + 1, col, m, n, dp) + up(o,row, col + 1, m, n,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int m = o.size();
        int n = o[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return up(o,0, 0, m, n, dp);
    }
};
