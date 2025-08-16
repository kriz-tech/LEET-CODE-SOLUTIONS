class Solution {
public:
    void backtrack(int start, vector<int>& curr, vector<vector<int>>& res, int n, int k){
        if(curr.size() == k){
            res.push_back(curr);
            return;
        }
        for(int i = start; i <= n; i++){
            curr.push_back(i);
            backtrack(i + 1, curr, res, n, k);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
       vector<vector<int>> res;
       vector<int> curr;
       backtrack(1, curr, res, n , k);
       return res; 
    }
};