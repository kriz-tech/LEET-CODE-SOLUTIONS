class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>res;
        for(int i = 0; i < n; i++){
            vector<int>sub_lst;
            int val = 1;
            for(int k = 0; k < i + 1; k++){
                sub_lst.push_back(val);
                val = val * (i - k)/(k + 1);
            }
            res.push_back(sub_lst);
        }
        return res;
    }
};