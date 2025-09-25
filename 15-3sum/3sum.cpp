class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1, right = n - 1;
            while(left < right){
                int sum = nums[i] + nums[right] + nums[left];
                if(sum < 0) left += 1;
                else if(sum > 0) right -= 1;
                else{
                    res.push_back({nums[i], nums[left], nums[right]});
                    left += 1;
                    right -= 1;
                    while(left < right && nums[left] == nums[left - 1]) left++;
                    while(left < right && nums[right] == nums[right + 1]) right--;

                }
            }
        }
        return res;
    }
};