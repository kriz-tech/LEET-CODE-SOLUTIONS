class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int>res(n, 0);
        stack<int>s;

        for(int i = 0; i < n; i++)
        {
            int count = 0;
            while(!s.empty() && t[i] > t[s.top()])
            {
                res[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};