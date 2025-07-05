class Solution {
public:
    int minD(string &word1, string &word2, int i, int j, vector<vector<int>>&dp){
        if(dp[i][j] != -1) return dp[i][j];

        if(i == 0) return dp[i][j] = j; if (j == 0) return dp[i][j] = i;
        if(word1[i - 1] == word2[j - 1]) return dp[i][j] = minD(word1, word2, i - 1, j - 1, dp);
        else{
            int in = 1 + minD(word1, word2, i, j - 1, dp);
            int de = 1 + minD(word1, word2, i - 1, j, dp);
            int re = 1 + minD(word1, word2, i - 1, j - 1, dp);
            return dp[i][j] = min(in, min(de, re));
        }
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>>dp(m + 1, vector<int>(n + 1, -1));
        return minD(word1, word2, word1.size(), word2.size(), dp);
    }
};