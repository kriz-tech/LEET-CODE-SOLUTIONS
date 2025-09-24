class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>pre_count;
        pre_count[0] = 1;

        int sum = 0, count = 0;

        for(auto num:nums){
            sum += num;

            if(pre_count.find(sum - k) != pre_count.end())
                count += pre_count[sum - k];
            pre_count[sum]++;
        }
        return count;
    }
};