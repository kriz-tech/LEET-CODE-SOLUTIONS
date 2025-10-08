class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size();

        while(left < right){
            int mid = left +  (right - left) / 2;
            int missing = arr[mid] - mid - 1;
            if(missing >= k) right = mid;
            else left = mid + 1;
        }
        return left + k;
    }
};