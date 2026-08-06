class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        unordered_map<int, int> seen;

        for(int x:nums){
            res += seen[x];
            seen[x] += 1;
        }
        return res;
    }
};