class Solution {
public:
    int LCS(int i, int j, int m, int n, string &s1, string &s2, vector<vector<int>>& dp)
    {
        if(i >= m || j >=n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j])
            return dp[i][j] = 1 + LCS(i + 1, j + 1, m, n, s1, s2, dp);
        else 
            return dp[i][j] = max(LCS(i + 1, j, m, n, s1, s2, dp), LCS(i, j + 1, m, n, s1, s2, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return LCS(0, 0, m, n, text1, text2, dp);
    }
};