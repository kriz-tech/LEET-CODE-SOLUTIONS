class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
    int max_num = nums[0];
    int idx = 0;
    for(int i = 0; i < n; i++)
    {
        max_num = max(nums[i], max_num);
        if(nums[i] == max_num) idx = i; 
    }
    return idx;
    }
};