class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr_sum = 0, max_sum = 0;

        for(auto num : nums){
            if(num == 1){
                curr_sum ++;
                max_sum = max(max_sum, curr_sum);
            }
            else{
                curr_sum = 0;
            }
        }
        return max_sum;
    }
};