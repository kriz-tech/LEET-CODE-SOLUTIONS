class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int>gaps(n + 1);

        gaps[0] = startTime[0];
        for(int i = 1; i < n; i++){
            gaps[i] = startTime[i] - endTime[i - 1];
        }
        gaps[n] = eventTime - endTime[n - 1];

        vector<int>leftMax(n + 1), rightMax(n + 1);

        leftMax[0] = gaps[0];
        for(int i = 1; i <= n; i++){
            leftMax[i] = max(leftMax[i - 1], gaps[i]);
        }

        rightMax[n] = gaps[n];

        for(int i = n - 1; i >= 0; i--){
            rightMax[i] = max(rightMax[i + 1], gaps[i]);
        }

        int res = 0;

        for(int i = 0; i < n; i++){
            int duration = endTime[i] - startTime[i];
            int adj = gaps[i] + gaps[i + 1];

            int maxother = 0;
            if(i > 0) maxother = max(maxother, leftMax[i - 1]);
            if(i + 2 <= n) maxother = max(maxother, rightMax[i + 2]);

            int extra = (duration <= maxother) ? duration : 0;

            res = max(res, adj + extra);
        }
        return res;
    }
};