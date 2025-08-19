class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int>seen;
        vector<int>res;

        for(auto num : nums){
            if(seen.count(num)) res.push_back(num);
            else seen.insert(num);
        }
        return res;
    }
};