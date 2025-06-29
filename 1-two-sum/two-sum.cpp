class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>res;
        unordered_map<int, int>m;
        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            int b = target - nums[i];
            if(m.count(b))
            {
                res.push_back(m[b]);
                res.push_back(i);
            }
            else m[nums[i]] = i;
        }
        return res;
    }
};