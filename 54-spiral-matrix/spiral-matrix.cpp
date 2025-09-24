class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& nums) {
        vector<int>res;
        if(nums.empty()) return res;

        int top = 0, bottom = nums.size() - 1;
        int left = 0, right = nums[0].size() - 1;

        while(top <= bottom && left <= right){
            for(int i = left; i <= right; i++)
                res.push_back(nums[top][i]);
            top++;

            for(int i = top; i <= bottom; i++)
                res.push_back(nums[i][right]);
            right -= 1;

            if(top <= bottom){
                for(int i = right; i >= left; i--)
                    res.push_back(nums[bottom][i]);
                bottom -= 1;
            }
            if(left <= right){
                for(int i = bottom; i >= top; i--)
                    res.push_back(nums[i][left]);
                left += 1;
            }
        }
        return res;
    }
};