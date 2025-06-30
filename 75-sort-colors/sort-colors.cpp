class Solution {
public:
    void swap(int *p1, int *p2)
    {
        int t = *p1;
        *p1 = *p2;
        *p2 = t;
    }
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zeroidx = 0, twoidx = n - 1;
        int itr = 0;

        while(itr <= twoidx)
        {
            if(nums[itr] == 0) swap(&nums[itr++], &nums[zeroidx++]);
            else if(nums[itr] == 1) ++itr;
            else swap(&nums[itr], &nums[twoidx--]);
        }
    }
};