class Solution {
public:
    int solve(int i, int k, vector<vector<int>>& events, vector<vector<int>>& dp){
        if(i == events.size() || k == 0) return 0;
        if(dp[i][k] != -1) return dp[i][k];

        int low = i + 1, high = events.size(), next = events.size();

        while(low < high){
            int mid = (low + high) / 2;
            if(events[mid][0] > events[i][1]){
                next = mid;
                high = mid;
            }
            else low = mid + 1;
        }
        int take = events[i][2] + solve(next, k - 1, events, dp);
        int skip = solve(i + 1, k, events, dp);

        return dp[i][k] = max(take, skip);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<vector<int>>dp(n, vector<int>(k + 1, -1));
        return solve(0, k, events, dp);
    }
};