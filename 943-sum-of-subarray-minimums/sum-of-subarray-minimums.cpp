class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        vector<int> ple(n), nle(n);
        stack<int> s;

        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] > arr[i]) s.pop();
            ple[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        while (!s.empty()) s.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            nle[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        long long res = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - ple[i];
            long long right = nle[i] - i;
            res = (res + arr[i] * left % MOD * right % MOD) % MOD;
        }

        return res;
    }
};