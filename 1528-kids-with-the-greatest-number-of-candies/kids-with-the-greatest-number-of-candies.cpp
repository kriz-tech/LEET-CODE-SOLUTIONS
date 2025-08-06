class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extra) {
        int n = candies.size();
        vector<bool>res(n, false);
        int max_value = *max_element(candies.begin(), candies.end());

        for(int i = 0; i < n; i++){
            if(candies[i] + extra >= max_value) res[i] = true;
        }
        return res;
    }
};