class Solution {
public:
    void backtrack(int start , vector<int>& curr, vector<vector<int>>& res, vector<int>& candidates, int target){
        if(target < 0)
            return ;
        if(target == 0){
            res.push_back(curr);
            return ;
        }
        for(int i = start; i < candidates.size(); i++){
            curr.push_back(candidates[i]);
            backtrack(i, curr, res, candidates, target - candidates[i]);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> res;
      vector<int> curr;
      backtrack(0, curr, res, candidates, target);
      return res;
    }
};