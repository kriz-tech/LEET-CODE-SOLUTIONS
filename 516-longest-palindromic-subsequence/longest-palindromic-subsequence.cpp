class Solution {
public:
    int LCS(int i, int j, int m, int n, string &s1, string & s2, vector<vector<int>>& dp)
    {
        if(i >= m || j >=n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j])
            return dp[i][j] = 1 + LCS(i + 1, j + 1, m, n, s1, s2, dp);
        else 
            return dp[i][j] = max(LCS(i + 1, j, m, n, s1, s2, dp), LCS(i, j + 1, m, n, s1, s2, dp));
    }
    int longestPalindromeSubseq(string s) {
        string ds = s;
        int n = s.size();
        reverse(ds.begin(), ds.end());
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return LCS(0, 0, n, n, s, ds, dp);
    }
};