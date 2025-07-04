class Solution {
public:
    int robb(vector<int>& nums, int start, int end)
    {
        int prev = 0, curr = nums[start],  next = 0;
        for(int i = start + 1; i <= end; i++)
        {
            next = max(curr, prev + nums[i]);
            prev = curr;
            curr = next;
        }
        return curr;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        int ans1 = robb(nums, 0, n - 2);
        int ans2 = robb(nums, 1, n - 1);
        return max(ans1, ans2);
    }
};