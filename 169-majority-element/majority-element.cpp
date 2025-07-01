class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n/2 + n % 2; i++)
          if(nums[i] == nums[i + n/2]) return nums[i];
        return 0;

    }
};