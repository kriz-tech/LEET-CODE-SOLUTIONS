class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>>pq;

        int n = events.size();
        int i = 0, res = 0;

        int last = 0;

        for(auto &e : events){
            last = max(last, e[1]);
        }

        for(int j = 1; j <= last; j++){
            while(i < n && events[i][0] == j){
                pq.push(events[i][1]);
                ++i;
            }
            while(!pq.empty() && pq.top() < j){
                pq.pop();
            }

            if(!pq.empty()){
                pq.pop();
                res++;
            }
        }
        return res;
    }
};