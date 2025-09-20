class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max_sum = nums[0], sum = 0;

        for(auto num:nums){
            sum = max(num, sum + num);
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};