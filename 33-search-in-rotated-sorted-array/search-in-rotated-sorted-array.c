int find_minIdx(int *a, int n){
    if(n == 1 || a[0] < a[n - 1]) return a[0];
    int left = 0, right = n - 1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(a[mid + 1] < a[mid]) return mid + 1;
        if(a[mid] < a[mid - 1]) return mid;
        if(a[0] < a[mid]) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
int binary_search(int *nums, int left, int right, int target){
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(nums[mid] == target) return mid;
        if(nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int search(int* nums, int n, int target) {
    int minIdx = find_minIdx(nums, n);
    int res =  binary_search(nums, 0, minIdx - 1, target);
    if(res != -1) return res;
    return binary_search(nums, minIdx, n -1 , target);
}