class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int>freq;
        for(auto num : nums) freq[num]++;

        vector<int>res;
        for(auto &n : freq){
            if(n.second > 1) res.push_back(n.first);
        }
        return res;
    }
};