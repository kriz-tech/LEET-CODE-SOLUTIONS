class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> res;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            int complement = target - nums[i];

            if(res.find(complement) != res.end())
                return {res[complement], i};

            res[nums[i]] = i;
        }
        return {};
    }
};