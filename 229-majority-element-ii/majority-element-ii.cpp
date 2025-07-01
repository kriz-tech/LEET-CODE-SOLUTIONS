class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>res;
        unordered_map<int, int>m;
        for(auto i : nums) m[i] += 1;
        for(auto i : m)
           if(i.second > nums.size()/3) res.push_back(i.first);
        return res;
    }
};