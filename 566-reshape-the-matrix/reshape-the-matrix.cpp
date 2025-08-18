class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if(m * n != r * c) return mat;
        vector<vector<int>>res(r, vector<int>(c));
        for(int idx = 0; idx < m * n; idx++){
            int row = idx / n, col = idx % n;
            int rows = idx / c, cols = idx % c;

            res[rows][cols] = mat[row][col];
        }
        return res;
    }
};