class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int pair_count = 0;
        unordered_map<int, int>m;//space complexity O(n)
        int n = nums.size();
        for(auto i : nums)
        {
            pair_count += m[i];
            m[i] += 1;
        }

        return pair_count;
    }
};