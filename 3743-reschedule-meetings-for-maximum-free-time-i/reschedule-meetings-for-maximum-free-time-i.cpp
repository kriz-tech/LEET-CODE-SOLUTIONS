class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int>gaps;

        gaps.push_back(startTime[0]);

        for(int i = 1; i < n; i++){
            gaps.push_back(startTime[i] - endTime[i - 1]);
        }

        gaps.push_back(eventTime - endTime[n - 1]);
        
        int windowssum = 0;

        for(int i = 0; i <= k && i < gaps.size(); i++){
            windowssum += gaps[i];
        }

        int maxgap = windowssum;

        for(int i = k + 1; i < gaps.size(); i++){
            windowssum += gaps[i] - gaps[i - k - 1];
            maxgap = max(maxgap, windowssum);
        }

        return maxgap;
    }
};