int findMin(int* nums, int n) {
    if(n == 1) return nums[0];// for avoiding heap overflow error
    if(nums[0] < nums[n - 1]) return nums[0];
    int left = 0, right = n - 1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(nums[mid] > nums[mid + 1]) return nums[mid + 1];
        if(nums[mid] < nums[mid - 1]) return nums[mid];
        if(nums[0] < nums[mid]) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}