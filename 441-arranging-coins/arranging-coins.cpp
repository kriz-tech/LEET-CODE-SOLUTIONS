class Solution {
public:
    int arrangeCoins(int n) {
        return (int) ((sqrt(1 + 8LL * n) - 1) / 2);
    }
};