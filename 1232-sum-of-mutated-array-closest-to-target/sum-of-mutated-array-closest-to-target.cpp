class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());

        int left = 0, right = *max_element(arr.begin(), arr.end());
        int result = 0, min_diff = INT_MAX;

        while (left <= right){
            int mid = (right + left) / 2;
            int total = 0;

            for(auto num : arr)
                total += min(mid, num);

            int diff = abs(total - target);

            if(diff < min_diff || (diff == min_diff && mid < result)){
                result = mid;
                min_diff = diff;
            }

            if(total < target) left = mid + 1;
            else right = mid - 1;
        }
        return result;
    }
};