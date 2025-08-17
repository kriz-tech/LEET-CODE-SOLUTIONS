class Solution {
public:
    double new21Game(int n, int k, int mp) {
        if(k == 0 || n >= k - 1 + mp) return 1.0;
        if(k > n) return 0.0;

        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;

        double sum = 1.0;
        double res = 0.0;

        for(int i = 1; i < n + 1; i++){
            dp[i] = sum/mp;
            if(i < k) sum += dp[i];
            else res += dp[i];

            if(i - mp >= 0) sum -= dp[i - mp];
        }
        return res;
    }
};