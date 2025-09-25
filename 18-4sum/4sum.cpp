class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue; //skip the duplicate
            for(int j = i + 1; j < n; j++){
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;

                long long new_target = (long long) target - nums[i] - nums[j];
                int left = j + 1, right = n - 1;

                while(left < right){
                    long long sum = (long long) nums[left] + nums[right];

                    if(sum < new_target) left += 1;
                    else if(sum > new_target) right -= 1;
                    else{
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left += 1;
                        right -= 1;

                        while(left < right && nums[left] == nums[left - 1]) left += 1;
                        while(left < right && nums[right] == nums[right + 1]) right -= 1;
                    }
                }
            }
        }
        return res;
    }
};