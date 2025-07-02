class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        int r = m.size();
        int c = m[0].size();

        int left = 0, right = r * c - 1;

        while(left <= right)
        {
            int mid = (left + right) / 2;
            int r_idx = mid/c;
            int c_idx = mid % c;
            if(m[r_idx][c_idx] == target) return true;
            if(target > m[r_idx][c_idx]) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};