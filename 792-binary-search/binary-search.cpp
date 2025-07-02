class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int k = 0;
        for(int i = n/2; i > 0; i /= 2)
            while(k + i < n && nums[k + i] <= target) k += i;
        if(nums[k] == target) return k;
        return -1;
        
    }
};