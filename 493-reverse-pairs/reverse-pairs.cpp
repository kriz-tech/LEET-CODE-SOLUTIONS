class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergesort(nums, 0, nums.size() - 1);
    }
private:
    int mergesort(vector<int>& nums, int l, int r){
        if(l >= r) return 0;
        int mid = l + (r - l) / 2;
        int count = mergesort(nums, l, mid) + mergesort(nums, mid+1, r);

        int j = mid + 1;
        for(int i = l; i <= mid; i++){
            while(j <= r && (long long)nums[i] > 2LL * nums[j]) j += 1;
            count += (j - (mid + 1));
        }

        merge(nums, l, mid, r);
        return count;
    }
    void merge(vector<int>& nums, int l, int mid, int r){
        vector<int> temp;
        int i = l, j = mid + 1;

        while (i <= mid && j <= r){
            if (nums[i] <= nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }

        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= r) temp.push_back(nums[j++]);

        for(int k = 0; k < temp.size(); k++){
            nums[l + k] = temp[k];
        }
    }
};