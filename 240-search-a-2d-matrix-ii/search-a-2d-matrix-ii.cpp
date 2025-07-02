class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target){
        int m = mat.size();// no.of rows
        int n = mat[0].size();// no.of columns
        int r_idx = m - 1;
        int c_idx = 0;

        while(c_idx < n && r_idx >= 0)
        {
            if(mat[r_idx][c_idx] == target) return true;
            if(mat[r_idx][c_idx] > target) r_idx--;
            else c_idx++;
        }
        return false;
    }
};