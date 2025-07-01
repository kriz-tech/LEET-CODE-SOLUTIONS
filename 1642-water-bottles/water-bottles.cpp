class Solution {
public:
    int numWaterBottles(int nb, int ne) {
        return nb + (nb - 1) / (ne - 1);
    }
};