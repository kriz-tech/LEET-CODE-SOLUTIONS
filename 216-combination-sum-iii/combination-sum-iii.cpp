class Solution {
public:
    void backtrack(int start, int n, int t, vector<int>& curr, vector<vector<int>>& res){
        if(curr.size() == n && t == 0)
        {
            res.push_back(curr);
            return ;
        }
        for(int i = start; i <= 9; i++){
            curr.push_back(i);
            backtrack(i + 1, n, t - i, curr, res);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int n, int t) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(1, n, t, curr, res);
        return res;
    }
};