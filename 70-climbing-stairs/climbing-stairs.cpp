int f[101];
class Solution {
public:
    int climbStairs(int n) {
        f[1] = 1;
        f[2] = 2;
        if(n == 1 || n == 2) return n;
        if(f[n] != 0) return f[n];
        f[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return f[n];
    }
};
//TC : O(2 ^ n) for 32 bits ranges from -2147483648 to 2147483647
// SC : depth of the recursion tree... 