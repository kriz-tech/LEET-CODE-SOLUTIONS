class Solution {
public:
    int climbstair(int i,vector<int>& cost, vector<int>& dp)
    {
        if(i >= cost.size()) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = cost[i] + min(climbstair(i + 1, cost, dp), climbstair(i + 2, cost, dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n, -1);
        return min(climbstair(0,cost, dp), climbstair(1, cost, dp));
    }
};