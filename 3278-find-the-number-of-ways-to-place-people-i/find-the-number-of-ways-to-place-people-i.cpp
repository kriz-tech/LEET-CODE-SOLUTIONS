class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] != b[0]  ? a[0] < b[0] : a[1] > b[1];
        });

        int n = points.size(), res = 0;

        for(int i = 0; i < n - 1; i++){
            int y1 = points[i][1];
            int max_y = INT_MIN;

            for(int j = i + 1; j < n; j++){
                int y2 = points[j][1];
                if(max_y < y2 && y2 <= y1){
                    res++;
                    max_y = y2;
                }
            }
        }
        return res;
    }
};