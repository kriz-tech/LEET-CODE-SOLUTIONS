class Solution {
public:
    int findPoisonedDuration(vector<int>& ts, int duration) {
        if(ts.empty()) return 0;

        int res = 0;
        for(int i = 0; i < ts.size() - 1; i++){
            res += min(duration, ts[i + 1] - ts[i]);
        }
        res += duration;
        return res;
    }
};