class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int idx = 0;
        for(int i = 0; i < nums.size(); i++) idx ^= nums[i];
        return idx;
    }
};