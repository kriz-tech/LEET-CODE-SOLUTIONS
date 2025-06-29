class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, int>m;
        long long pair_count = 0;
        for(auto i : rectangles)
        {
            double ratio = (double) i[0]/i[1];
            pair_count += m[ratio];
            m[ratio] += 1;
        }
        return pair_count;
    }
};