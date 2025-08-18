class Solution {
public:
    const double eps = 1e-6;
    bool judgePoint24(vector<int>& nums) {
        vector<double>arr(nums.begin(), nums.end());
        return dfs(arr);
    }

    bool dfs(vector<double>& nums){
        if(nums.size() == 1) return abs(nums[0] - 24) < eps;

        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                double a = nums[i], b = nums[j];
                vector<double>next;

                for(int k = 0; k < n; k++)
                    if(k != i && k != j) next.push_back(nums[k]);
                
                vector<double>candidate = {a + b, a * b, a - b, b - a};
                if(abs(b) > eps) candidate.push_back(a/b);
                if(abs(a) > eps) candidate.push_back(b/a);

                for(double c : candidate){
                    next.push_back(c);
                    if(dfs(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }
};