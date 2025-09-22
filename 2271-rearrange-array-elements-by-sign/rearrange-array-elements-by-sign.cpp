class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n), pos, neg;

        for(auto num : nums){
            if(num >= 0) pos.push_back(num);
            else neg.push_back(num);
        }
        int k = 0, j = 0;
        for(int i = 0; i < n; i++){
            if(i % 2 == 0) res[i] = pos[j++];
            else res[i] = neg[k++];
        }
        return res;
    }
};