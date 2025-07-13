class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        sort(p.begin(), p.end());
        sort(t.begin(), t.end());

        int res = 0, j = 0;

        for(int i = 0; i < t.size() && j < p.size(); i++){
            if(p[j] <= t[i]){
                res++;
                j++;
            }
        }
        return res;

    }
};